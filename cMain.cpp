#include "cMain.h"

wxBEGIN_EVENT_TABLE(cMain, wxMDIParentFrame)
    wxEND_EVENT_TABLE();

cMain::cMain() : wxMDIParentFrame(nullptr, wxID_ANY, "wxWidgets Video", wxPoint(30, 30), wxSize(800, 600))
{
}

cMain::~cMain()
{
}
