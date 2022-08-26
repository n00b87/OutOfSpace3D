/***************************************************************
 * Name:      rc_ide2App.cpp
 * Purpose:   Code for Application Class
 * Author:     ()
 * Created:   2015-08-18
 * Copyright:  ()
 * License:
 **************************************************************/

//#include "wx_pch.h"
#include "OOS3D_App.h"


#include "OOS3D_Engine_Frame.h"
#include <wx/image.h>

IMPLEMENT_APP_CONSOLE(OOS3D_App);

bool OOS3D_App::OnInit()
{
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	OOS3D_Engine_Frame* Frame = new OOS3D_Engine_Frame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    return wxsOK;

}

int OOS3D_App::OnExit()
{
    //Potentially add shutdown message here
    return 0;
}
