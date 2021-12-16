/***************************************************************
 * Name:      kalkApp.cpp
 * Purpose:   Code for Application Class
 * Author:     ()
 * Created:   2021-12-16
 * Copyright:  ()
 * License:
 **************************************************************/

#include "kalkApp.h"

//(*AppHeaders
#include "kalkMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(kalkApp);

bool kalkApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	kalkFrame* Frame = new kalkFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
