#pragma once

#include <wx/wx.h>

class cMain : public wxFrame
{
public:
    cMain();
    ~cMain();

public:
    int nFieldWidth = 10;
    int nFieldHeight = 10;
    wxButton **btn;

    // wxDECLARE_EVENT_TABLE();

    void OnButtonClicked(wxCommandEvent &evt);
};