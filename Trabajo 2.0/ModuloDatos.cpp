 // Grupo: 233
 // Nombres: Eduardo Santos Navarro y Jesús Ferrándiz Alarcón
 // Fecha: 17/10/2018

//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "ModuloDatos.h"
//---------------------------------------------------------------------------

#pragma package(smart_init)

// Datos de Rebose:

        static EnumRebose Rebose = Rebose_False;

        void Datos_AlmacenarRebose(EnumRebose dato)  //Lectura
        {
                Rebose = dato; //Rebose True o False.
        }

        EnumRebose Datos_ConsultarRebose(void) //Consulta
        {
                return(Rebose);
        }

//Datos Sobrecalentamiento Generador ¿?:

        static EnumSobre Sobrecalentamiento = Sobrecalentamiento_False;

        void Datos_AlmacenarSobrecalentamiento(EnumSobre dato)   //Lectura
        {
                Sobrecalentamiento = dato;
        }

        EnumSobre Datos_ConsultarSobrecalentamiento(void)    //Consulta
        {
                return(Sobrecalentamiento);
        }

//Datos Compuerta

        static double Compuerta;

        void Datos_AlmacenarCompuerta(double dato)  //Lectura
        {
                Compuerta = dato;
        }

        double Datos_ConsultarCompuerta(void)      //Consulta
        {
                return(Compuerta);
        }

// Datos de Bomba:

        static EnumBomba Bomba = Bomba_Off;

        void Datos_AlmacenarBomba(EnumBomba dato)  //Lectura
        {
                Bomba = dato; //Rebose True o False.
        }

        EnumBomba Datos_ConsultarBomba(void) //Consulta
        {
                return(Bomba);
        }

//Datos Temperatura Generador ¿?:

        static double Temperatura = 25;

        void Datos_AlmacenarTemperatura(double dato)  //Lectura
        {
                Temperatura = dato;
        }

        double Datos_ConsultarTemperatura(void)  //Consulta
        {
                return(Temperatura);
        }

//Datos Nivel Presa:

        static double Nivel = 1900;

        void Datos_AlmacenarNivel(double dato)    //Lectura
        {
                Nivel = dato;
        }

        double Datos_ConsultarNivel(void)   //Consulta
        {
                return(Nivel);
        }

//Datos Refrigeracion Generador:

        static double Refrigeracion = 0;

        void Datos_AlmacenarRefrigeracion(double dato)   //Lectura
        {
                Refrigeracion = dato;
        }

        double Datos_ConsultarRefrigeracion(void)  //Consulta
        {
                return(Refrigeracion);
        }


//Datos Potencia Producida:

        static double Potencia = 1900;

        void Datos_AlmacenarPotencia(double dato)    //Lectura
        {
                Potencia = dato;
        }

        double Datos_ConsultarPotencia(void)   //Consulta
        {
                return(Potencia);
        }



//Consigna TemperaturaObjetivo:

        static double TemperaturaObjetivo = 25;

        void Datos_AlmacenarTemperaturaObjetivo(double dato)  //Lectura
        {
                TemperaturaObjetivo = dato;
        }

        double Datos_ConsultarTemperaturaObjetivo(void)  //Consulta
        {
                return(TemperaturaObjetivo);
        }

//Consigna NIvel Objetivo:

        static double NivelObjetivo = 1900;

        void Datos_AlmacenarNivelObjetivo(double dato)  //Lectura
        {
                NivelObjetivo = dato;
        }

        double Datos_ConsultarNivelObjetivo(void)  //Consulta
        {
                return(NivelObjetivo);
        }

//Error Proceso

        long errdaq = 0;

        void Datos_AlmacenarErrdaq(long dato)    //Lectura
        {
                errdaq = dato;
        }

        long Datos_ConsultarErrdaq(void)     //Consulta
        {
                return(errdaq);
        }

//Mensaje error

        AnsiString msgError;

        void Datos_AlmacenarmsgError(AnsiString dato)
        {
                msgError = dato;
        }

        AnsiString Datos_ConsultarmsgError(void)
        {
                return(msgError);
        }

