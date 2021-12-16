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
const long kalkFrame::ID_BUTTON1 = wxNewId();
const long kalkFrame::ID_BUTTON2 = wxNewId();
const long kalkFrame::ID_BUTTON3 = wxNewId();
const long kalkFrame::ID_BUTTON4 = wxNewId();
const long kalkFrame::ID_BUTTON5 = wxNewId();
const long kalkFrame::ID_BUTTON6 = wxNewId();
const long kalkFrame::ID_BUTTON7 = wxNewId();
const long kalkFrame::ID_BUTTON8 = wxNewId();
const long kalkFrame::ID_BUTTON9 = wxNewId();
const long kalkFrame::ID_BUTTON10 = wxNewId();
const long kalkFrame::ID_BUTTON11 = wxNewId();
const long kalkFrame::ID_BUTTON12 = wxNewId();
const long kalkFrame::ID_BUTTON13 = wxNewId();
const long kalkFrame::ID_BUTTON14 = wxNewId();
const long kalkFrame::ID_BUTTON15 = wxNewId();
const long kalkFrame::ID_BUTTON16 = wxNewId();
const long kalkFrame::ID_BUTTON17 = wxNewId();
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

    complex_num add_number(complex_num num1, complex_num num2, complex_num res)
    {
        res.real = num1.real + num2.real;
        res.im = num1.im + num2.im;
        return res;
    }
    complex_num sub_number(complex_num num1, complex_num num2, complex_num res)
    {
        res.real = num1.real - num2.real;
        res.im = num1.im - num2.im;
        return res;
    }
    complex_num mul_number(complex_num num1, complex_num num2, complex_num res)
    {
        res.real = num1.real * num2.real - num1.im * num2.im;
        res.im = num1.real * num2.im + num1.im * num2.real;
        return res;
    }
    complex_num div_number(complex_num num1, complex_num num2, complex_num res)
    {
        res.real = (num1.real * num2.real + num1.im * num2.im) / (num2.real * num2.real + num2.im * num2.im);
        res.im = (-(num1.real * num2.im) - num1.real * num1.im) / (num2.real * num2.real + num2.im * num2.im);
        return res;
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

    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    SetClientSize(wxSize(393,444));
    TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxPoint(8,8), wxSize(184,23), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    Button1 = new wxButton(this, ID_BUTTON1, _("1"), wxPoint(8,40), wxSize(40,40), 0, wxDefaultValidator, _T("ID_BUTTON1"));
    Button2 = new wxButton(this, ID_BUTTON2, _("2"), wxPoint(56,40), wxSize(40,40), 0, wxDefaultValidator, _T("ID_BUTTON2"));
    Button3 = new wxButton(this, ID_BUTTON3, _("3"), wxPoint(104,40), wxSize(40,40), 0, wxDefaultValidator, _T("ID_BUTTON3"));
    Button4 = new wxButton(this, ID_BUTTON4, _("4"), wxPoint(8,88), wxSize(40,40), 0, wxDefaultValidator, _T("ID_BUTTON4"));
    Button5 = new wxButton(this, ID_BUTTON5, _("5"), wxPoint(56,88), wxSize(40,40), 0, wxDefaultValidator, _T("ID_BUTTON5"));
    Button6 = new wxButton(this, ID_BUTTON6, _("6"), wxPoint(104,88), wxSize(40,40), 0, wxDefaultValidator, _T("ID_BUTTON6"));
    Button7 = new wxButton(this, ID_BUTTON7, _("7"), wxPoint(8,136), wxSize(40,40), 0, wxDefaultValidator, _T("ID_BUTTON7"));
    Button8 = new wxButton(this, ID_BUTTON8, _("8"), wxPoint(56,136), wxSize(40,40), 0, wxDefaultValidator, _T("ID_BUTTON8"));
    Button9 = new wxButton(this, ID_BUTTON9, _("9"), wxPoint(104,136), wxSize(40,40), 0, wxDefaultValidator, _T("ID_BUTTON9"));
    Button10 = new wxButton(this, ID_BUTTON10, _("0"), wxPoint(8,184), wxSize(40,40), 0, wxDefaultValidator, _T("ID_BUTTON10"));
    Button11 = new wxButton(this, ID_BUTTON11, _("i"), wxPoint(56,184), wxSize(40,40), 0, wxDefaultValidator, _T("ID_BUTTON11"));
    Button12 = new wxButton(this, ID_BUTTON12, _("clr"), wxPoint(104,184), wxSize(40,40), 0, wxDefaultValidator, _T("ID_BUTTON12"));
    Button13 = new wxButton(this, ID_BUTTON13, _("+"), wxPoint(152,40), wxSize(40,40), 0, wxDefaultValidator, _T("ID_BUTTON13"));
    Button14 = new wxButton(this, ID_BUTTON14, _("-"), wxPoint(152,88), wxSize(40,40), 0, wxDefaultValidator, _T("ID_BUTTON14"));
    Button15 = new wxButton(this, ID_BUTTON15, _("*"), wxPoint(152,136), wxSize(40,40), 0, wxDefaultValidator, _T("ID_BUTTON15"));
    Button16 = new wxButton(this, ID_BUTTON16, _("/"), wxPoint(152,184), wxSize(40,40), 0, wxDefaultValidator, _T("ID_BUTTON16"));
    Button17 = new wxButton(this, ID_BUTTON17, _("="), wxPoint(8,232), wxSize(184,32), 0, wxDefaultValidator, _T("ID_BUTTON17"));
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

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&kalkFrame::OnButton1Click);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&kalkFrame::OnButton2Click);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&kalkFrame::OnButton3Click);
    Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&kalkFrame::OnButton4Click);
    Connect(ID_BUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&kalkFrame::OnButton5Click);
    Connect(ID_BUTTON6,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&kalkFrame::OnButton6Click);
    Connect(ID_BUTTON7,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&kalkFrame::OnButton7Click);
    Connect(ID_BUTTON8,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&kalkFrame::OnButton8Click);
    Connect(ID_BUTTON9,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&kalkFrame::OnButton9Click);
    Connect(ID_BUTTON10,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&kalkFrame::OnButton10Click);
    Connect(ID_BUTTON11,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&kalkFrame::OnButton11Click);
    Connect(ID_BUTTON12,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&kalkFrame::OnButton12Click);
    Connect(ID_BUTTON13,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&kalkFrame::OnButton13Click);
    Connect(ID_BUTTON14,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&kalkFrame::OnButton14Click);
    Connect(ID_BUTTON15,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&kalkFrame::OnButton15Click);
    Connect(ID_BUTTON16,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&kalkFrame::OnButton16Click);
    Connect(ID_BUTTON17,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&kalkFrame::OnButton17Click);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&kalkFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&kalkFrame::OnAbout);
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

wxString fast, last, r;
float ans;
int operators;

void kalkFrame::OnButton1Click(wxCommandEvent& event)
{
    if(TextCtrl1->GetValue()!="" && TextCtrl1->GetValue().Last() == 'i') TextCtrl1->SetValue("");
    if(TextCtrl1->GetValue()=="0")
    {
        TextCtrl1->SetValue(Button1->GetLabel());
    }
    else
    {
        TextCtrl1->AppendText(Button1->GetLabel());
    }
}

void kalkFrame::OnButton2Click(wxCommandEvent& event)
{
    if(TextCtrl1->GetValue()!="" && TextCtrl1->GetValue().Last() == 'i') TextCtrl1->SetValue("");
    if(TextCtrl1->GetValue()=="0")
    {
        TextCtrl1->SetValue(Button2->GetLabel());
    }
    else
    {
        TextCtrl1->AppendText(Button2->GetLabel());
    }
}

void kalkFrame::OnButton3Click(wxCommandEvent& event)
{
    if(TextCtrl1->GetValue()!="" && TextCtrl1->GetValue().Last() == 'i') TextCtrl1->SetValue("");
    if(TextCtrl1->GetValue()=="0")
    {
        TextCtrl1->SetValue(Button3->GetLabel());
    }
    else
    {
        TextCtrl1->AppendText(Button3->GetLabel());
    }
}

void kalkFrame::OnButton4Click(wxCommandEvent& event)
{
    if(TextCtrl1->GetValue()!="" && TextCtrl1->GetValue().Last() == 'i') TextCtrl1->SetValue("");
    if(TextCtrl1->GetValue()=="0")
    {
        TextCtrl1->SetValue(Button4->GetLabel());
    }
    else
    {
        TextCtrl1->AppendText(Button4->GetLabel());
    }
}

void kalkFrame::OnButton5Click(wxCommandEvent& event)
{
    if(TextCtrl1->GetValue()!="" && TextCtrl1->GetValue().Last() == 'i') TextCtrl1->SetValue("");
    if(TextCtrl1->GetValue()=="0")
    {
        TextCtrl1->SetValue(Button5->GetLabel());
    }
    else
    {
        TextCtrl1->AppendText(Button5->GetLabel());
    }
}

void kalkFrame::OnButton6Click(wxCommandEvent& event)
{
    if(TextCtrl1->GetValue()!="" && TextCtrl1->GetValue().Last() == 'i') TextCtrl1->SetValue("");
    if(TextCtrl1->GetValue()=="0")
    {
        TextCtrl1->SetValue(Button6->GetLabel());
    }
    else
    {
        TextCtrl1->AppendText(Button6->GetLabel());
    }
}

void kalkFrame::OnButton7Click(wxCommandEvent& event)
{
    if(TextCtrl1->GetValue()!="" && TextCtrl1->GetValue().Last() == 'i') TextCtrl1->SetValue("");
    if(TextCtrl1->GetValue()=="0")
    {
        TextCtrl1->SetValue(Button7->GetLabel());
    }
    else
    {
        TextCtrl1->AppendText(Button7->GetLabel());
    }
}

void kalkFrame::OnButton8Click(wxCommandEvent& event)
{
    if(TextCtrl1->GetValue()!="" && TextCtrl1->GetValue().Last() == 'i') TextCtrl1->SetValue("");
    if(TextCtrl1->GetValue()=="0")
    {
        TextCtrl1->SetValue(Button8->GetLabel());
    }
    else
    {
        TextCtrl1->AppendText(Button8->GetLabel());
    }
}

void kalkFrame::OnButton9Click(wxCommandEvent& event)
{
    if(TextCtrl1->GetValue()!="" && TextCtrl1->GetValue().Last() == 'i') TextCtrl1->SetValue("");
    if(TextCtrl1->GetValue()=="0")
    {
        TextCtrl1->SetValue(Button9->GetLabel());
    }
    else
    {
        TextCtrl1->AppendText(Button9->GetLabel());
    }
}

void kalkFrame::OnButton10Click(wxCommandEvent& event)
{
    if(TextCtrl1->GetValue()!="" && TextCtrl1->GetValue().Last() == 'i') TextCtrl1->SetValue("");
    if(TextCtrl1->GetValue()=="0")
    {
        TextCtrl1->SetValue(Button10->GetLabel());
    }
    else
    {
        TextCtrl1->AppendText(Button10->GetLabel());
    }
}

void kalkFrame::OnButton11Click(wxCommandEvent& event)
{
    if(TextCtrl1->GetValue()!="" && TextCtrl1->GetValue().Last() == 'i') TextCtrl1->SetValue("");
    if(TextCtrl1->GetValue()=="0")
    {
        TextCtrl1->SetValue(Button11->GetLabel());
    }
    else
    {
        TextCtrl1->AppendText(Button11->GetLabel());
    }
}

void kalkFrame::OnButton12Click(wxCommandEvent& event)
{
    TextCtrl1->SetValue("");
    num1.reset();
    num2.reset();
    result.reset();
}

void kalkFrame::OnButton13Click(wxCommandEvent& event)
{
    fast = TextCtrl1->GetValue();
    if(fast.Last() == 'i') num1.im = wxAtoi(fast);
    if(fast.Last() != 'i') num1.real = wxAtoi(fast);
    operators = 1;  /// +
    TextCtrl1->SetValue("");
}

void kalkFrame::OnButton14Click(wxCommandEvent& event)
{
    fast = TextCtrl1->GetValue();
    if(fast.Last() == 'i') num1.im = wxAtoi(fast);
    if(fast.Last() != 'i') num1.real = wxAtoi(fast);
    operators = 2;  /// -
    TextCtrl1->SetValue("");
}

void kalkFrame::OnButton15Click(wxCommandEvent& event)
{
    fast = TextCtrl1->GetValue();
    if(fast.Last() == 'i') num1.im = wxAtoi(fast);
    if(fast.Last() != 'i') num1.real = wxAtoi(fast);
    operators = 3;  /// *
    TextCtrl1->SetValue("");
}

void kalkFrame::OnButton16Click(wxCommandEvent& event)
{
    fast = TextCtrl1->GetValue();
    if(fast.Last() == 'i') num1.im = wxAtoi(fast);
    if(fast.Last() != 'i') num1.real = wxAtoi(fast);
    operators = 4;  /// /
    TextCtrl1->SetValue("");
}

void kalkFrame::OnButton17Click(wxCommandEvent& event)
{
    last = TextCtrl1->GetValue();
    if(last.Last() == 'i') num2.im = wxAtoi(last);
    if(last.Last() != 'i') num2.real = wxAtoi(last);
    switch(operators)
    {
    case 1:
        result = num1.add_number(num1,num2,result);
        break;
    case 2:
        result = num1.sub_number(num1,num2,result);
        break;
    case 3:
        result = num1.mul_number(num1,num2,result);
        break;
    case 4:
        result = num1.div_number(num1,num2,result);
        break;
    }
    TextCtrl1->SetValue("");
    r = wxString::Format(wxT("%g"),result.real);
    TextCtrl1->AppendText(r);
    TextCtrl1->AppendText(" + ");
    r = wxString::Format(wxT("%g"),result.im);
    TextCtrl1->AppendText(r);
    TextCtrl1->AppendText("i");


    num1.reset();
    num2.reset();
    result.reset();

}
