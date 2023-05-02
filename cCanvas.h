#pragma once

#include <wx/wx.h>
#include <wx/vscroll.h>

class cCanvas : public wxHVScrolledWindow
{
public:
    cCanvas(wxWindow *parent);
    ~cCanvas();

    void SetPixelSize(int n);

private:
    wxDECLARE_EVENT_TABLE();

    int m_nPixelSize = 8;
    
    wxColour palette[16];

    virtual wxCoord OnGetRowHeight(size_t row) const;
    virtual wxCoord OnGetColumnWidth(size_t row) const;

    void OnDraw(wxDC &dc);
    void OnPaint(wxPaintEvent &evt);
};