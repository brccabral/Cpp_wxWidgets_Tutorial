#pragma once

#include <wx/wx.h>
#include <wx/vscroll.h>

class cCanvas : public wxHVScrolledWindow
{
public:
    cCanvas(wxWindow *parent);
    ~cCanvas();
    
    wxDECLARE_EVENT_TABLE();

private:
    virtual wxCoord OnGetRowHeight(size_t row) const;
    virtual wxCoord OnGetColumnHeight(size_t row) const;
};