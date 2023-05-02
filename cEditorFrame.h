#pragma once

#include <wx/wx.h>

#include "cCanvas.h"

class cEditorFrame : public wxMDIChildFrame
{
public:
    cEditorFrame(wxMDIParentFrame *parent, wxString sName);
    ~cEditorFrame();

private:
    cCanvas *m_Canvas = nullptr;

    wxStatusBar *m_StatusBar = nullptr;
    wxSlider *m_ZoomSlider = nullptr;

    void OnZoomChange(wxCommandEvent &evt);
    
    wxDECLARE_EVENT_TABLE();
};
