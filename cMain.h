#pragma once

#include <wx/wx.h>

class cMain : public wxMDIParentFrame
{
public:
    cMain();
    ~cMain();

private:
    wxMenuBar *m_MenuBar = nullptr;

    wxDECLARE_EVENT_TABLE();

    void OnMenuNew(wxCommandEvent &evt);
    void OnMenuOpen(wxCommandEvent &evt);
    void OnMenuSave(wxCommandEvent &evt);
    void OnMenuExit(wxCommandEvent &evt);

};