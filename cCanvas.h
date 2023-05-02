#pragma once

#include <wx/wx.h>
#include <wx/vscroll.h>

class cCanvas : public wxHVScrolledWindow
{
public:
    cCanvas(wxWindow *parent);
    ~cCanvas();

    void SetPixelSize(int n);
    void SetSpriteData(int rows, int columns, unsigned char *pSprite);
    void SetColor(int c);

private:
    wxDECLARE_EVENT_TABLE();

    int m_nPixelSize = 8;
    unsigned char *m_pSprite = nullptr;
    int m_nColour = 0;
    
    wxColour palette[16];

    virtual wxCoord OnGetRowHeight(size_t row) const;
    virtual wxCoord OnGetColumnWidth(size_t row) const;

    void OnDraw(wxDC &dc);
    void OnPaint(wxPaintEvent &evt);
};