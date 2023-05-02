#include "cCanvas.h"

wxBEGIN_EVENT_TABLE(cCanvas, wxHVScrolledWindow)
    wxEND_EVENT_TABLE();

cCanvas::cCanvas(wxWindow *parent)
    : wxHVScrolledWindow(parent, wxID_ANY)
{
    SetRowColumnCount(40, 40);
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
