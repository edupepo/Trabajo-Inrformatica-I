//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("ModuloUsuario.cpp", PantallaPrincipal);
USEFORM("ss_visual_niusb6008.cpp", F_niusb6008);
USEFORM("ss_visual_signal.cpp", F_signaled);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->CreateForm(__classid(TPantallaPrincipal), &PantallaPrincipal);
                 Application->CreateForm(__classid(TF_niusb6008), &F_niusb6008);
                 Application->CreateForm(__classid(TF_signaled), &F_signaled);
                 Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        catch (...)
        {
                 try
                 {
                         throw Exception("");
                 }
                 catch (Exception &exception)
                 {
                         Application->ShowException(&exception);
                 }
        }
        return 0;
}
//---------------------------------------------------------------------------
