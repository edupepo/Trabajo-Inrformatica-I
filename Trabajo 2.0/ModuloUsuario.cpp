// Eduardo Santos Navarro, Jesús Ferrándiz Alarcón, Grupo 233

//---------------------------------------------------------------------------
#include "ModuloDatos.h"
#include "ModuloProceso.h"
#include <vcl.h>
#pragma hdrstop

#include "ModuloUsuario.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TPantallaPrincipal *PantallaPrincipal;
//---------------------------------------------------------------------------
__fastcall TPantallaPrincipal::TPantallaPrincipal(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TPantallaPrincipal::BIniciarClick(TObject *Sender)
{
        //Inicio del proceso.

                Inicio_Proceso_IO();
                //Implementar salida del proceso
                

        //Mostrar errores de comunicación.
        if(Datos_ConsultarErrdaq() != 0)
        {
                ShowMessage(Datos_ConsultarmsgError());
                PantallaPrincipal->LComunicacion->Caption = "Ha fallado la comunicación";
                exit(1);
        }
        else
        {
                PantallaPrincipal->LComunicacion->Caption = "No hay error de comunicación.";
        }

}

//---------------------------------------------------------------------------


        double Usuario_LeerTemperaturaObjetivo(void){

                return(PantallaPrincipal->ETemperatura->Text.ToDouble());  //Mirar lo del error de no es un real de la practica.

        }

        double Usuario_LeerNivelObjetivo(void){

                    return(PantallaPrincipal->ENivel->Text.ToDouble());

        }

        EnumModoControl Leer_Modo_Control(void){

                if(PantallaPrincipal->RControlAutomatico->Checked == true)
                return(Control_Automatico);

                else
                return(Control_Manual);
        }

void __fastcall TPantallaPrincipal::RControlManualClick(TObject *Sender)
{
    BCalefaccion->Enabled = true;
    BValvula->Enabled = true;
    SBomba->Enabled = true;
    Lbombam->Enabled = true;

    ETemperatura->Enabled = false;
    ENivel->Enabled = false;
    LTemperaturao->Enabled = false;
    LNivelo->Enabled = false;

}
//---------------------------------------------------------------------------

void __fastcall TPantallaPrincipal::RControlAutomaticoClick(TObject *Sender)
{
    BCalefaccion->Enabled = false;
    BValvula->Enabled = false;
    SBomba->Enabled = false;
    Lbombam->Enabled = false;

    LTemperaturao->Enabled = true;
    LNivelo->Enabled = true;
    ETemperatura->Enabled = true;
    ENivel->Enabled = true;
}
//---------------------------------------------------------------------------





