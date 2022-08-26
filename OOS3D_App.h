/***************************************************************
 * Name:      rc_ide2App.h
 * Purpose:   Defines Application Class
 * Author:     ()
 * Created:   2015-08-18
 * Copyright:  ()
 * License:
 **************************************************************/

#ifndef OOS3D_IDEAPP_H
#define OOS3D_IDEAPP_H

#include <wx/app.h>

class OOS3D_App : public wxApp
{
    public:
        virtual bool OnInit();
        virtual int OnExit();
};

#endif // OOS3D_IDEAPP_H
