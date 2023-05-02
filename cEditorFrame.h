#pragma once

#include <wx/wx.h>

class cEditorFrame : public wxMDIChildFrame
{
public:
    cEditorFrame(wxMDIParentFrame *parent, wxString sName);
    ~cEditorFrame();
};
