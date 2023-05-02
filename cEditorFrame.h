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
};
