#include "cMain.h"

wxBEGIN_EVENT_TABLE(cMain, wxMDIParentFrame)
EVT_MENU(10001, cMain::OnMenuNew)
EVT_MENU(10002, cMain::OnMenuOpen)
EVT_MENU(10003, cMain::OnMenuSave)
EVT_MENU(10004, cMain::OnMenuExit)
wxEND_EVENT_TABLE();

cMain::cMain() : wxMDIParentFrame(nullptr, wxID_ANY, "wxWidgets Video", wxPoint(30, 30), wxSize(800, 600))
{
    // create a menu bar
    m_MenuBar = new wxMenuBar();
    this->SetMenuBar(m_MenuBar);

    // create a menu "File"
    wxMenu *menuFile = new wxMenu();
    menuFile->Append(10001, "New");
    menuFile->Append(10002, "Open");
    menuFile->Append(10003, "Save");
    menuFile->Append(10004, "Exit");

    // add menu "File" to the bar
    m_MenuBar->Append(menuFile, "File");
}

cMain::~cMain()
{
}

void cMain::OnMenuNew(wxCommandEvent &evt)
{
}

void cMain::OnMenuOpen(wxCommandEvent &evt)
{
}

void cMain::OnMenuSave(wxCommandEvent &evt)
{
}

void cMain::OnMenuExit(wxCommandEvent &evt)
{
    Close();
    evt.Skip();
}
