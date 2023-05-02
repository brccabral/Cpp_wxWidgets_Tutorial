#pragma once

#include <wx/wx.h>
#include <wx/vscroll.h>

class cCanvas : public wxHVScrolledWindow
{
public:
    cCanvas(wxWindow *parent);
    ~cCanvas();
    
    wxDECLARE_EVENT_TABLE();

    void SetPixelSize(int n);

private:
    int m_nPixelSize = 8;

    virtual wxCoord OnGetRowHeight(size_t row) const;
    virtual wxCoord OnGetColumnWidth(size_t row) const;
};