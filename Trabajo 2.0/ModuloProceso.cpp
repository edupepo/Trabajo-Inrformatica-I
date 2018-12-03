//---------------------------------------------------------------------------
#pragma hdrstop

#include "ModuloUsuario.h"
#include "ModuloDatos.h"
#include "vcl.h"
#include "ModuloProceso.h"

#define SS_FALSE_DAQ
#include "ss_nidaqmx.h"

//#include "nidaqmx.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

long errdaq;
int Valor_Puerto;

 // process error reporting --------------------------------------------------
void ErrorProceso(int32 code, char *suffix) {
 AnsiString msg;
 char buff[200]; // buffer for the error message
 msg = "Error: ";
 msg = msg + suffix;
 msg = msg + "\n";
 msg = msg + "In: ";
 DAQmxGetErrorString (code, buff, 200); // get the error message
 msg = msg + buff;
 //PantallaPrincipal->LComunicacion->Caption = "Ha fallado la comunicación";  //Cuidado Que se nos acopla el programa
 //ShowMessage(msg);
 Datos_AlmacenarmsgError(msg);
 Datos_AlmacenarErrdaq(code);
 //exit(1); // force the end of the application
}


//Tareas:
TaskHandle SensorD_rebose;
TaskHandle SensorD_sobrecalentamiento;
TaskHandle ActuadorA_compuerta;
TaskHandle ActuadorD_bomba;
TaskHandle SensorA_temperatura;
TaskHandle SensorA_nivel;
TaskHandle ActuadorA_refrigeracion;
TaskHandle SensorA_potencia;

        void Inicio_Proceso_IO(void) {

        Valor_Puerto = 0x00;

        //Rebose
        errdaq = DAQmxCreateTask("SensorD_rebose",&SensorD_rebose);
        errdaq = DAQmxCreateDIChan(SensorD_rebose,"Dev9/port0", "",DAQmx_Val_ChanForAllLines);
        if(errdaq!=0)
        {
                        ErrorProceso(errdaq, "Inicio_Proceso_IO() Rebose");
                        return;
        }


        //Sobrecalentamiento
        errdaq = DAQmxCreateTask("SensorD_sobrecalentamiento",&SensorD_sobrecalentamiento);
        errdaq = DAQmxCreateDIChan(SensorD_sobrecalentamiento,"Dev9/port0", "",DAQmx_Val_ChanForAllLines);
        if(errdaq!=0)
        {
                        ErrorProceso(errdaq, "Inicio_Proceso_IO() Sobrecalentamiento");
                        return;
        }

        //Compuerta
        errdaq = DAQmxCreateTask("ActuadorA_compuerta",&ActuadorA_compuerta);
        errdaq = DAQmxCreateAOVoltageChan(ActuadorA_compuerta,"Dev9/ao0", "", 0.0, 5.0, DAQmx_Val_Volts, NULL);
        if(errdaq!=0)
        {
                        ErrorProceso(errdaq, "Inicio_Proceso_IO() Compuerta");
                        return;
        }

        //Bomba
        errdaq = DAQmxCreateTask("ActuadorD_bomba",&ActuadorD_bomba);
        errdaq = DAQmxCreateDOChan(ActuadorD_bomba,"Dev9/port1", "",DAQmx_Val_ChanForAllLines);
        if(errdaq!=0)
        {
                        ErrorProceso(errdaq, "Inicio_Proceso_IO() Calentador");
                        return;
        }

        //Temperatura
        errdaq = DAQmxCreateTask("SensorA_temperatura",&SensorA_temperatura);
        errdaq = DAQmxCreateAIVoltageChan(SensorA_temperatura,"Dev9/ai0", "",DAQmx_Val_RSE, 0.0, 10.0, DAQmx_Val_Volts, NULL);
        if(errdaq!=0)
        {
                        ErrorProceso(errdaq, "Inicio_Proceso_IO() Temperatura");
                        return;
        }

        //Nivel
        errdaq = DAQmxCreateTask("SensorA_nivel",&SensorA_nivel);
        errdaq = DAQmxCreateAIVoltageChan(SensorA_nivel,"Dev9/ai1", "",DAQmx_Val_RSE, 0.0, 6.0, DAQmx_Val_Volts, NULL);
        if(errdaq!=0)
        {
                        ErrorProceso(errdaq, "Inicio_Proceso_IO() Nivel");
                        return;
        }

        //Refrigeracion
        errdaq = DAQmxCreateTask("ActuadorA_refrigeracion",&ActuadorA_refrigeracion);
        errdaq = DAQmxCreateAOVoltageChan(ActuadorA_refrigeracion,"Dev9/ao1", "", 0.0, 5.0, DAQmx_Val_Volts, NULL);
        if(errdaq!=0)
        {
                        ErrorProceso(errdaq, "Inicio_Proceso_IO() Bomba");
                        return;
        }
                }



        //Leer Rebose proceso:

        EnumRebose Proceso_LeerRebose(void){

                uInt32 data;

                errdaq = DAQmxReadDigitalScalarU32(SensorD_rebose,0.0,&data,NULL);
                if(errdaq!=0)
                {
                        ErrorProceso(errdaq,"proceso_LeerRebose()");
                        ShowMessage("Abandonando Proceso");
                        exit(1);
                }
                if ((data & 0x01) == 0){

                        return(Rebose_True); //Datos_AlmacenarRebose()
                        }
                        else {
                                return(Rebose_False);
                                }
                }

        //Leer Sobrecalentamiento proceso:

        EnumSobre Proceso_LeerSobrecalentamiento(void){

                uInt32 data;

                errdaq = DAQmxReadDigitalScalarU32(SensorD_sobrecalentamiento,0.0,&data,NULL);
                if(errdaq!=0)
                {
                        ErrorProceso(errdaq,"proceso_LeerSobrecalentamiento()");
                        ShowMessage("Abandonando Proceso");
                        exit(1);
                }

                if ((data & 0x02>1) == 0){
                        return(Sobrecalentamiento_False);
                        }
                        else {
                                return(Sobrecalentamiento_True);
                                }
                }

        //Actuar Compuerta proceso:

        void Proceso_EscribirCompuerta(double referencia){

                double voltios;

                voltios = referencia/20.0;

                errdaq = DAQmxWriteAnalogScalarF64(ActuadorA_compuerta,true,1.0,voltios,NULL);
                if (errdaq != 0)
                {
                        ErrorProceso(errdaq,"proceso_EscribirBomba");
                        ShowMessage("Abandonando Proceso");
                        exit(1);
                }
                }

        //Actuar Bomba proceso:

        void Proceso_EscribirBomba(EnumBomba estado){

                if(estado == Bomba_On)
                        Valor_Puerto = Valor_Puerto & ~0X02;
                else
                        Valor_Puerto = Valor_Puerto & 0x02;

                errdaq = DAQmxWriteDigitalScalarU32 (ActuadorD_bomba, true, 0.0, Valor_Puerto, NULL);
                if (errdaq != 0)
                {
                        ErrorProceso(errdaq,"proceso_EscribirBomba");
                        ShowMessage("Abandonando Proceso");
                        exit(1);
                }
                        }

        //Leer Temperatura proceso:

        double Proceso_LeerTemperatura(void){

                double voltios;
                double grados;

                errdaq = DAQmxReadAnalogScalarF64(SensorA_temperatura,1.0,&voltios,NULL);
                if (errdaq != 0)
                {
                        ErrorProceso(errdaq,"proceso_LeerTemperatura");
                        ShowMessage("Abandonando Proceso");
                        exit(1);
                }

                grados=voltios*(100.0/10.0);
                return(grados);   
                 }

        //Leer Nivel proceso:

        double Proceso_LeerNivel(void){

                double voltios;
                double litros;

                errdaq = DAQmxReadAnalogScalarF64(SensorA_nivel,1.0,&voltios,NULL);
                if (errdaq != 0)
                ErrorProceso(errdaq,"proceso_LeerNivel");

                litros=voltios*(-3800.0/6.0)+3800;
                return(litros);
                 }

        //Actuador Bomba proceso:

        void Proceso_EscribirRefrigreracion(double referencia){

                double voltios;

                voltios = referencia/20.0;

                errdaq = DAQmxWriteAnalogScalarF64(ActuadorA_refrigeracion,true,1.0,voltios,NULL);
                if (errdaq != 0)
                {
                        ErrorProceso(errdaq,"proceso_EscribirRefrigeracion");
                        ShowMessage("Abandonando Proceso");
                        exit(1);
                }
                        }






