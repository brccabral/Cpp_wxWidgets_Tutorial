#include "cMain.h"

wxBEGIN_EVENT_TABLE(cMain, wxMDIParentFrame)
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
