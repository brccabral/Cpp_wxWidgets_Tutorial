#pragma once

#include <wx/wx.h>

#include "cEditorFrame.h"

class cMain : public wxMDIParentFrame
{
public:
    cMain();
    ~cMain();

private:
    wxMenuBar *m_MenuBar = nullptr;
    // * typically is used to add buttons like "Save", "Copy/Paste"
    // * we use to show the color palette.
    wxToolBar *m_ToolBar = nullptr;
#ifndef _WIN32
    wxStatusBar *m_MainStatusBar = nullptr;
    wxSlider *m_ZoomSlider = nullptr;
    void OnZoomChange(wxCommandEvent &evt);
#endif

    wxDECLARE_EVENT_TABLE();

    void OnMenuNew(wxCommandEvent &evt);
    void OnMenuOpen(wxCommandEvent &evt);
    void OnMenuSave(wxCommandEvent &evt);
    void OnMenuExit(wxCommandEvent &evt);

    void OnSelectColour(wxCommandEvent &evt);

};