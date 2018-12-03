//---------------------------------------------------------------------------

#ifndef ModuloProcesoH
#define ModuloProcesoH

//---------------------------------------------------------------------------

        //Lecturas y escrituras en tarjeta.
        //CAMBIAR LOS INT POR ENUM.
        EnumRebose Proceso_LeerRebose(void);

        EnumSobre Proceso_LeerSobrecalentamiento(void);

        double Proceso_LeerTemperatura(void);

        double Proceso_LeerNivel(void);

        void Proceso_EscribirRefrigeracion(double);

        void Proceso_EscribirBomba(EnumBomba);

        void Proceso_EscribirCompuerta(double);

        //Inicio de Proceso.
        void Inicio_Proceso_IO(void);

        
       

#endif
