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

    pen.SetStyle(wxPENSTYLE_LONG_DASH);
    pen.SetColour(wxColour(200, 200, 200));

    dc.SetPen(pen);
    dc.SetBrush(brush);
    dc.DrawRectangle(20, 20, 200, 200);
}

void cCanvas::OnPaint(wxPaintEvent &evt)
{
    wxBufferedPaintDC dc(this); // * DC = Device Context
    this->PrepareDC(dc);
    this->OnDraw(dc);
    evt.Skip();
}
