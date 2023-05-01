#include "cMain.h"

#define BUTTON1_ID 10001

wxBEGIN_EVENT_TABLE(cMain, wxFrame)

    EVT_BUTTON(BUTTON1_ID, cMain::OnButtonClicked)

wxEND_EVENT_TABLE();

cMain::cMain() : wxFrame(nullptr, wxID_ANY, "wxWidgets Video", wxPoint(30, 30), wxSize(800, 600))
{
    m_btn1 = new wxButton(this, BUTTON1_ID, "Click me", wxPoint(10, 10), wxSize(150, 50));
    m_txt1 = new wxTextCtrl(this, wxID_ANY, "", wxPoint(10, 70), wxSize(300, 30));
    m_list1 = new wxListBox(this, wxID_ANY, wxPoint(10, 110), wxSize(300, 300));
}

cMain::~cMain()
{
}

void cMain::OnButtonClicked(wxCommandEvent &evt)
{
    m_list1->AppendString(m_txt1->GetValue());
    evt.Skip(); // * tells that the event has been handled
}