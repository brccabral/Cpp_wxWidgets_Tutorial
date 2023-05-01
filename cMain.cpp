#include "cMain.h"

wxBEGIN_EVENT_TABLE(cMain, wxFrame)
    wxEND_EVENT_TABLE();

cMain::cMain() : wxFrame(nullptr, wxID_ANY, "wxWidgets Video", wxPoint(30, 30), wxSize(800, 600))
{
    btn = new wxButton *[nFieldWidth * nFieldHeight];
    wxGridSizer *grid = new wxGridSizer(nFieldWidth, nFieldHeight, 0, 0);

    nField = new int[nFieldWidth * nFieldHeight];

    wxFont font(24, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false);

    for (int x = 0; x < nFieldWidth; x++)
    {
        for (int y = 0; y < nFieldHeight; y++)
        {
            int index = y * nFieldHeight + x;
            btn[index] = new wxButton(this, 10000 + index);
            grid->Add(btn[index], 1, wxEXPAND | wxALL);

            btn[index]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &cMain::OnButtonClicked, this);
            btn[index]->SetFont(font);
        }
    }
    this->SetSizer(grid);
    grid->Layout();

    ResetGame();
}

cMain::~cMain()
{
    delete[] btn;
}

void cMain::OnButtonClicked(wxCommandEvent &evt)
{
    // evt.GetId() = Button ID

    // get coordinate of button in field array
    int x = (evt.GetId() - 10000) % nFieldWidth;
    int y = (evt.GetId() - 10000) / nFieldWidth;

    int index = y * nFieldWidth + x;

    if (bFirstClick)
    {
        std::srand(time(0));

        int mines = 30;

        while (mines)
        {
            int rx = rand() % nFieldWidth;
            int ry = rand() % nFieldHeight;
            int rindex = ry * nFieldWidth + rx;

            if (nField[rindex] == 0 && rx != x && ry != y)
            {
                nField[rindex] = -1;
                mines--;
            }
        }

        bFirstClick = false;
    }

    btn[index]->Enable(false); // * disables button

    // check if player hit mine
    if (nField[index] == -1)
    {
        // * show all mines
        for (int x = 0; x < nFieldWidth; x++)
        {
            for (int y = 0; y < nFieldHeight; y++)
            {
                int index = y * nFieldHeight + x;
                if (nField[index] < 0)
                    btn[index]->SetLabel(std::to_string(nField[index]));
            }
        }
        wxMessageBox("BOOM!! Game Over :(");
        ResetGame();
    }
    else
    {
        // count neighbouring mines
        int mine_count = 0;
        for (int i = -1; i < 2; i++)
            for (int j = -1; j < 2; j++)
            {
                // * boundaries
                if (x + i >= 0 && x + i < nFieldWidth && y + j >= 0 && y + j < nFieldHeight)
                    if (nField[(y + j) * nFieldHeight + (x + i)] == -1)
                        mine_count++;
            }

        if (mine_count > 0)
            btn[index]->SetLabel(std::to_string(mine_count));
    }

    evt.Skip(); // * tells that the event has been handled
}

void cMain::ResetGame()
{
    bFirstClick = true;
    for (int x = 0; x < nFieldWidth; x++)
    {
        for (int y = 0; y < nFieldHeight; y++)
        {
            int index = y * nFieldHeight + x;
            nField[index] = 0;
            btn[index]->SetLabel("");
            btn[index]->Enable(true);
        }
    }
}
