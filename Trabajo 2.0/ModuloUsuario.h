//---------------------------------------------------------------------------

#ifndef ModuloUsuarioH
#define ModuloUsuarioH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TPantallaPrincipal : public TForm
{
__published:	// IDE-managed Components
        TButton *BIniciar;
        TLabel *LComunicacion;
        TTimer *Timer1;
        TEdit *ETemperatura;
        TEdit *ENivel;
        TRadioButton *RControlAutomatico;
        TRadioButton *RControlManual;
        TScrollBar *SBomba;
        TButton *BCalefaccion;
        TButton *BValvula;
        TStaticText *Lbombam;
        TStaticText *LTemperaturao;
        TStaticText *LNivelo;
        TShape *Shape1;
        void __fastcall BIniciarClick(TObject *Sender);
        void __fastcall RControlManualClick(TObject *Sender);
        void __fastcall RControlAutomaticoClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TPantallaPrincipal(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TPantallaPrincipal *PantallaPrincipal;
//---------------------------------------------------------------------------


//Leer las consignas:

double Usuario_LeerTemperaturaObjetivo(void);
double Usuario_LeerNivelObjetivo(void);

enum EnumModoControl {Control_Automatico, Control_Manual};
EnumModoControl Leer_Modo_Control(void); //Cambiar por un enum CONTROL MANUAL O AMUTOMATICO.

#endif
