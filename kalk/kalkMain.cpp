/***************************************************************
 * Name:      kalkMain.cpp
 * Purpose:   Code for Application Frame
 * Author:     ()
 * Created:   2021-12-16
 * Copyright:  ()
 * License:
 **************************************************************/

#include "kalkMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(kalkFrame)
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(kalkFrame)
const long kalkFrame::ID_TEXTCTRL1 = wxNewId();
const long kalkFrame::ID_TEXTCTRL2 = wxNewId();
const long kalkFrame::ID_STATICTEXT1 = wxNewId();
const long kalkFrame::ID_STATICTEXT2 = wxNewId();
const long kalkFrame::ID_TEXTCTRL3 = wxNewId();
const long kalkFrame::ID_TEXTCTRL4 = wxNewId();
const long kalkFrame::ID_BUTTON1 = wxNewId();
const long kalkFrame::ID_BUTTON2 = wxNewId();
const long kalkFrame::ID_BUTTON3 = wxNewId();
const long kalkFrame::ID_BUTTON4 = wxNewId();
const long kalkFrame::ID_STATICTEXT3 = wxNewId();
const long kalkFrame::ID_TEXTCTRL5 = wxNewId();
const long kalkFrame::ID_STATICTEXT4 = wxNewId();
const long kalkFrame::ID_STATICTEXT5 = wxNewId();
const long kalkFrame::idMenuQuit = wxNewId();
const long kalkFrame::idMenuAbout = wxNewId();
const long kalkFrame::ID_STATUSBAR1 = wxNewId();
//*)

class complex_num
{
    public:
    float real = 0;
    float im = 0;

    complex_num reset()
    {
        this->real = 0;
        this->im = 0;
    }

    complex_num add_number(complex_num num1, complex_num num2)
    {
        this->real = num1.real + num2.real;
        this->im = num1.im + num2.im;
    }
    complex_num sub_number(complex_num num1, complex_num num2)
    {
        this->real = num1.real - num2.real;
        this->im = num1.im - num2.im;
    }
    complex_num mul_number(complex_num num1, complex_num num2)
    {
        this->real = num1.real * num2.real - num1.im * num2.im;
        this->im = num1.real * num2.im + num1.im * num2.real;
    }
    complex_num div_number(complex_num num1, complex_num num2)
    {
        this->real = (num1.real * num2.real + num1.im * num2.im) / (num2.real * num2.real + num2.im * num2.im);
        this->im = (-(num1.real * num2.im) - num1.real * num1.im) / (num2.real * num2.real + num2.im * num2.im);
    }

    char checkSign()
    {
        if(this->im > 0) return '+';
        else return '-';
    }
};





BEGIN_EVENT_TABLE(kalkFrame,wxFrame)
    //(*EventTable(kalkFrame)
    //*)
END_EVENT_TABLE()

kalkFrame::kalkFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(kalkFrame)
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(393,444));
    TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxPoint(136,8), wxSize(80,23), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    TextCtrl2 = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxPoint(240,8), wxSize(72,23), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Pierwsza liczba"), wxPoint(16,16), wxSize(96,16), wxALIGN_LEFT|wxALIGN_RIGHT|wxALIGN_CENTRE, _T("ID_STATICTEXT1"));
    StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Druga liczba"), wxPoint(24,48), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    TextCtrl3 = new wxTextCtrl(this, ID_TEXTCTRL3, wxEmptyString, wxPoint(136,48), wxSize(80,23), 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
    TextCtrl4 = new wxTextCtrl(this, ID_TEXTCTRL4, wxEmptyString, wxPoint(240,48), wxSize(72,23), 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
    Button1 = new wxButton(this, ID_BUTTON1, _("+"), wxPoint(56,88), wxSize(40,32), 0, wxDefaultValidator, _T("ID_BUTTON1"));
    Button2 = new wxButton(this, ID_BUTTON2, _("-"), wxPoint(128,88), wxSize(40,32), 0, wxDefaultValidator, _T("ID_BUTTON2"));
    Button3 = new wxButton(this, ID_BUTTON3, _("*"), wxPoint(200,88), wxSize(40,32), 0, wxDefaultValidator, _T("ID_BUTTON3"));
    Button4 = new wxButton(this, ID_BUTTON4, _("/"), wxPoint(280,88), wxSize(40,32), 0, wxDefaultValidator, _T("ID_BUTTON4"));
    StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Wynik"), wxPoint(40,152), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    TextCtrl5 = new wxTextCtrl(this, ID_TEXTCTRL5, wxEmptyString, wxPoint(160,144), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL5"));
    StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("i"), wxPoint(320,8), wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    wxFont StaticText4Font(20,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    StaticText4->SetFont(StaticText4Font);
    StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("i"), wxPoint(320,48), wxDefaultSize, 0, _T("ID_STATICTEXT5"));
    wxFont StaticText5Font(20,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    StaticText5->SetFont(StaticText5Font);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);

    Connect(ID_TEXTCTRL1,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&kalkFrame::OnTextCtrl1Text);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&kalkFrame::OnButton1Click1);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&kalkFrame::OnButton2Click1);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&kalkFrame::OnButton3Click1);
    Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&kalkFrame::OnButton4Click1);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&kalkFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&kalkFrame::OnAbout);
    Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&kalkFrame::OnClose);
    //*)
}

kalkFrame::~kalkFrame()
{
    //(*Destroy(kalkFrame)
    //*)
}

void kalkFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void kalkFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

complex_num num1;
complex_num num2;
complex_num result;

wxString temp;
float ansReal, ansIm;
char sign;
int operators;



void kalkFrame::OnTextCtrl1Text(wxCommandEvent& event)
{
}

void kalkFrame::OnButton1Click1(wxCommandEvent& event)
{
    TextCtrl5->Clear();
    num1.real = wxAtof(TextCtrl1->GetValue());
    num1.im = wxAtof(TextCtrl2->GetValue());
    num2.real = wxAtof(TextCtrl3->GetValue());
    num2.im = wxAtof(TextCtrl4->GetValue());
    result.add_number(num1,num2);
    TextCtrl5->AppendText(wxString::Format(wxT("%.2f"), result.real));
    TextCtrl5->AppendText(result.checkSign());
    TextCtrl5->AppendText(wxString::Format(wxT("%.2f"), abs(result.im)));
}

void kalkFrame::OnButton2Click1(wxCommandEvent& event)
{
    TextCtrl5->Clear();
    num1.real = wxAtof(TextCtrl1->GetValue());
    num1.im = wxAtof(TextCtrl2->GetValue());
    num2.real = wxAtof(TextCtrl3->GetValue());
    num2.im = wxAtof(TextCtrl4->GetValue());
    result.sub_number(num1,num2);
    TextCtrl5->AppendText(wxString::Format(wxT("%.2f"), result.real));
    TextCtrl5->AppendText(result.checkSign());
    TextCtrl5->AppendText(wxString::Format(wxT("%.2f"), abs(result.im)));
}

void kalkFrame::OnButton3Click1(wxCommandEvent& event)
{
    TextCtrl5->Clear();
    num1.real = wxAtof(TextCtrl1->GetValue());
    num1.im = wxAtof(TextCtrl2->GetValue());
    num2.real = wxAtof(TextCtrl3->GetValue());
    num2.im = wxAtof(TextCtrl4->GetValue());
    result.mul_number(num1,num2);
    TextCtrl5->AppendText(wxString::Format(wxT("%.2f"), result.real));
    TextCtrl5->AppendText(result.checkSign());
    TextCtrl5->AppendText(wxString::Format(wxT("%.2f"), abs(result.im)));
}

void kalkFrame::OnButton4Click1(wxCommandEvent& event)
{
    TextCtrl5->Clear();
    num1.real = wxAtof(TextCtrl1->GetValue());
    num1.im = wxAtof(TextCtrl2->GetValue());
    num2.real = wxAtof(TextCtrl3->GetValue());
    num2.im = wxAtof(TextCtrl4->GetValue());
    result.div_number(num1,num2);
    TextCtrl5->AppendText(wxString::Format(wxT("%.2f"), result.real));
    TextCtrl5->AppendText(result.checkSign());
    TextCtrl5->AppendText(wxString::Format(wxT("%.2f"), abs(result.im)));
}

void kalkFrame::OnClose(wxCloseEvent& event)
{
    kalkFrame::Close();
}
