/***************************************************************
 * Name:      kalkMain.h
 * Purpose:   Defines Application Frame
 * Author:     ()
 * Created:   2021-12-16
 * Copyright:  ()
 * License:
 **************************************************************/

#ifndef KALKMAIN_H
#define KALKMAIN_H

//(*Headers(kalkFrame)
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/stattext.h>
#include <wx/statusbr.h>
#include <wx/textctrl.h>
//*)

class kalkFrame: public wxFrame
{
    public:

        kalkFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~kalkFrame();

    private:

        //(*Handlers(kalkFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        void OnButton2Click(wxCommandEvent& event);
        void OnButton3Click(wxCommandEvent& event);
        void OnButton4Click(wxCommandEvent& event);
        void OnButton5Click(wxCommandEvent& event);
        void OnButton6Click(wxCommandEvent& event);
        void OnButton7Click(wxCommandEvent& event);
        void OnButton8Click(wxCommandEvent& event);
        void OnButton9Click(wxCommandEvent& event);
        void OnButton10Click(wxCommandEvent& event);
        void OnButton11Click(wxCommandEvent& event);
        void OnButton12Click(wxCommandEvent& event);
        void OnButton13Click(wxCommandEvent& event);
        void OnButton14Click(wxCommandEvent& event);
        void OnButton15Click(wxCommandEvent& event);
        void OnButton16Click(wxCommandEvent& event);
        void OnButton17Click(wxCommandEvent& event);
        void OnButton1Click1(wxCommandEvent& event);
        void OnTextCtrl1Text(wxCommandEvent& event);
        void OnButton1Click2(wxCommandEvent& event);
        void OnButton2Click1(wxCommandEvent& event);
        void OnButton3Click1(wxCommandEvent& event);
        void OnButton4Click1(wxCommandEvent& event);
        void OnClose(wxCloseEvent& event);
        //*)

        //(*Identifiers(kalkFrame)
        static const long ID_TEXTCTRL1;
        static const long ID_TEXTCTRL2;
        static const long ID_STATICTEXT1;
        static const long ID_STATICTEXT2;
        static const long ID_TEXTCTRL3;
        static const long ID_TEXTCTRL4;
        static const long ID_BUTTON1;
        static const long ID_BUTTON2;
        static const long ID_BUTTON3;
        static const long ID_BUTTON4;
        static const long ID_STATICTEXT3;
        static const long ID_TEXTCTRL5;
        static const long ID_STATICTEXT4;
        static const long ID_STATICTEXT5;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(kalkFrame)
        wxButton* Button1;
        wxButton* Button2;
        wxButton* Button3;
        wxButton* Button4;
        wxStaticText* StaticText1;
        wxStaticText* StaticText2;
        wxStaticText* StaticText3;
        wxStaticText* StaticText4;
        wxStaticText* StaticText5;
        wxStatusBar* StatusBar1;
        wxTextCtrl* TextCtrl1;
        wxTextCtrl* TextCtrl2;
        wxTextCtrl* TextCtrl3;
        wxTextCtrl* TextCtrl4;
        wxTextCtrl* TextCtrl5;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // KALKMAIN_H
