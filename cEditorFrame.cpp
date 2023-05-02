#include "cEditorFrame.h"

cEditorFrame::cEditorFrame(wxMDIParentFrame *parent, wxString sName)
    : wxMDIChildFrame(parent, wxID_ANY, sName)
{
}

cEditorFrame::~cEditorFrame()
{
}