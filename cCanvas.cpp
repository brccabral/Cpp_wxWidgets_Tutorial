#include "cCanvas.h"

#include <wx/dcclient.h>
#include <wx/dcmemory.h>
#include <wx/dcbuffer.h>

wxBEGIN_EVENT_TABLE(cCanvas, wxHVScrolledWindow)
    EVT_PAINT(cCanvas::OnPaint)
        wxEND_EVENT_TABLE();

cCanvas::cCanvas(wxWindow *parent)
    : wxHVScrolledWindow(parent, wxID_ANY)
{
    SetRowColumnCount(40, 40);
    // * tell widget that we are going to draw on it, not the wxWdiget library
    SetBackgroundStyle(wxBG_STYLE_PAINT);

    palette[0] = wxColour(0, 0, 0);
    palette[1] = wxColour(0, 0, 128);
    palette[2] = wxColour(0, 128, 0);
    palette[3] = wxColour(0, 128, 128);
    palette[4] = wxColour(128, 0, 0);
    palette[5] = wxColour(128, 0, 128);
    palette[6] = wxColour(128, 128, 0);
    palette[7] = wxColour(192, 192, 192);
    palette[8] = wxColour(128, 128, 128);
    palette[9] = wxColour(0, 0, 255);
    palette[10] = wxColour(0, 255, 0);
    palette[11] = wxColour(0, 255, 255);
    palette[12] = wxColour(255, 0, 0);
    palette[13] = wxColour(255, 0, 255);
    palette[14] = wxColour(255, 255, 0);
    palette[15] = wxColour(255, 255, 255);
}

cCanvas::~cCanvas()
{
}

wxCoord cCanvas::OnGetRowHeight(size_t row) const
{
    return wxCoord(m_nPixelSize);
}

wxCoord cCanvas::OnGetColumnWidth(size_t row) const
{
    return wxCoord(m_nPixelSize);
}

void cCanvas::SetPixelSize(int n)
{
    m_nPixelSize = n;
    wxVarHScrollHelper::RefreshAll(); // * horizontal scroll
    wxVarVScrollHelper::RefreshAll(); // * vertical scroll
    Refresh();
}

void cCanvas::OnDraw(wxDC &dc)
{
    dc.Clear();

    wxBrush brush = dc.GetBrush(); // * how
    wxPen pen = dc.GetPen();       // * boundary

    wxPosition s = GetVisibleBegin();
    wxPosition e = GetVisibleEnd();

    pen.SetStyle(wxPENSTYLE_LONG_DASH);
    pen.SetColour(wxColour(200, 200, 200));

    dc.SetPen(pen);

    // * show grid of cells
    for (int y = s.GetRow(); y < e.GetRow(); y++)
    {
        for (int x = s.GetCol(); x < e.GetCol(); x++)
        {
            int colour = m_pSprite[y * this->GetColumnCount() + x];
            if (colour < 16)
            {
                brush.SetColour(palette[colour]);
                brush.SetStyle(wxBRUSHSTYLE_SOLID);
            }
            else
            {
                // * ALPHA pattern
                brush.SetColour(wxColour(0, 0, 0));
                brush.SetStyle(wxBrushStyle::wxBRUSHSTYLE_CROSSDIAG_HATCH);
            }

            dc.SetBrush(brush);
            dc.DrawRectangle(x * m_nPixelSize, y * m_nPixelSize, m_nPixelSize, m_nPixelSize);
        }
    }
}

void cCanvas::OnPaint(wxPaintEvent &evt)
{
    wxBufferedPaintDC dc(this); // * DC = Device Context
    this->PrepareDC(dc);
    this->OnDraw(dc);
    evt.Skip();
}

void cCanvas::SetSpriteData(int rows, int columns, unsigned char *pSprite)
{
    m_pSprite = pSprite;
    this->SetRowColumnCount(rows, columns);
}

void cCanvas::SetColor(int c)
{
    m_nColour = c;
}