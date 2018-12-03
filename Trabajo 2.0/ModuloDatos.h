//---------------------------------------------------------------------------
#include <vcl.h>
#ifndef ModuloDatosH
#define ModuloDatosH
//---------------------------------------------------------------------------


        //Rebose:
    enum EnumRebose {Rebose_True, Rebose_False};
    void Datos_AlmacenarRebose(EnumRebose dato);
    EnumRebose Datos_ConsultarRebose(void);

        //Sobrecalentamiento:
    enum EnumSobre {Sobrecalentamiento_False, Sobrecalentamiento_True};
    void Datos_AlmacenarSobrecalentamiento(EnumSobre dato);
    EnumSobre Datos_ConsultarSobrecalentamiento(void);

        //Compuerta
    void Datos_AlmacenarCompuerta(double dato);
    double Datos_ConsultarCompuerta(void);

        //Bomba reversible:
    enum EnumBomba {Bomba_On, Bomba_Off};
    void Datos_AlmacenaBomba(EnumBomba dato);
    EnumBomba Datos_ConsultarBomba(void);

        //Temperatura
    void Datos_AlmacenarTemperatura(double dato);
    double Datos_ConsultarTemperatura(void);

        //Nivel
    void Datos_AlmacenarNivel(double dato);
    double Datos_ConsultarNivel(void);

        //Refrigeracion
    void Datos_AlmacenarRefrigeracion(double dato);
    double Datos_ConsultarRefrigeracion(void);

        //Potencia Producida
    void Datos_AlmacenarPotencia(double dato);
    double Datos_ConsultarPotencia(void);

        //TemperaturaObjetivo
    void Datos_AlmacenarTemperaturaObjetivo(double dato);
    double Datos_ConsultarTemperaturaObjetivo(void);

        //NivelObjetivo
    void Datos_AlmacenarNivelObjetivo(double dato);
    double Datos_ConsultarNivelObjetivo(void);

        //Errdaq
    void Datos_AlmacenarErrdaq(long dato);
    long Datos_ConsultarErrdaq(void);

        //msgError
    void Datos_AlmacenarmsgError(AnsiString dato);
    AnsiString Datos_ConsultarmsgError(void);

#endif
