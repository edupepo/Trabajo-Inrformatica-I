//Eduardo Santos Navarro, Jes�s Ferr�ndiz Alarc�n

//---------------------------------------------------------------------------


#pragma hdrstop

#include "ModuloTareas.h"
#include "ModuloDatos.h"
#include "ModuloProceso.h"
#include "ModuloControl.h"
#include "ModuloUsuario.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

    void Inspeccionar(void){

        //Almacenamos los datos:
        Datos_AlmacenarRebose(Proceso_LeerRebose());

        Datos_AlmacenarSobrecalentamiento(Proceso_LeerSobrecalentamiento());

        Datos_AlmacenarTemperatura(Proceso_LeerTemperatura());

        Datos_AlmacenarNivel(Proceso_LeerNivel());

        }

    void Parametrizar(void){

        //Almacenar las consignas:

        Datos_AlmacenarTemperaturaObjetivo(Usuario_LeerTemperaturaObjetivo());

        Datos_AlmacenarNivelObjetivo(Usuario_LeerNivelObjetivo());

        }

   void Decidir(void){

        switch(Leer_Modo_Control()){

                case 0:  //Control_Manual:

                        //Control manual por el usuario

                        break;

                case 1:   //Control_Automatico:

                        Control();

                        break;
                }
        }

   void Accionar(void){

          //Escribir en los actuadores:
          Proceso_EscribirBomba(Datos_ConsultarBomba());

          Proceso_EscribirRefrigeracion(Datos_ConsultarRefrigeracion());

          Proceso_EscribirCompuerta(Datos_ConsultarCompuerta());

        }

   void Visualizar(void){

        //Se implementa en el m�dulo de usuario

        }

   void Secuenciacion(void){

        Inspeccionar();
        Parametrizar();
        Decidir();
        Accionar();
        Visualizar();

        }
















