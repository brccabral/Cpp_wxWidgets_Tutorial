#include "cCanvas.h"

wxBEGIN_EVENT_TABLE(cCanvas, wxHVScrolledWindow)
    wxEND_EVENT_TABLE();

cCanvas::cCanvas(wxWindow *parent)
    : wxHVScrolledWindow(parent, wxID_ANY)
{
}

cCanvas::~cCanvas()
{
}

wxCoord cCanvas::OnGetRowHeight(size_t row) const
{
    return wxCoord(0);
}

wxCoord cCanvas::OnGetColumnHeight(size_t row) const
{
    return wxCoord(0);
}
