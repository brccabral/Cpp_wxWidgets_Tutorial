#include "cMain.h"

// wxBEGIN_EVENT_TABLE(cMain, wxFrame)

//     EVT_BUTTON(BUTTON1_ID, cMain::OnButtonClicked)

// wxEND_EVENT_TABLE();

cMain::cMain() : wxFrame(nullptr, wxID_ANY, "wxWidgets Video", wxPoint(30, 30), wxSize(800, 600))
{
    btn = new wxButton *[nFieldWidth * nFieldHeight];
    wxGridSizer *grid = new wxGridSizer(nFieldWidth, nFieldHeight, 0, 0);

    for (int x = 0; x < nFieldWidth; x++)
    {
        for (int y = 0; y < nFieldHeight; y++)
        {
            int index = y * nFieldHeight + x;
            btn[index] = new wxButton(this, 10000 + index);
            grid->Add(btn[index], 1, wxEXPAND | wxALL);
        }
    }
    this->SetSizer(grid);
    grid->Layout();
}

cMain::~cMain()
{
    delete[] btn;
}

void cMain::OnButtonClicked(wxCommandEvent &evt)
{
    evt.Skip(); // * tells that the event has been handled
}