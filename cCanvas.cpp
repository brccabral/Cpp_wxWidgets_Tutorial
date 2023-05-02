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
