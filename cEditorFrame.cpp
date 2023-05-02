#include "cEditorFrame.h"

wxBEGIN_EVENT_TABLE(cEditorFrame, wxMDIChildFrame)
    wxEND_EVENT_TABLE();

cEditorFrame::cEditorFrame(wxMDIParentFrame *parent, wxString sName)
    : wxMDIChildFrame(parent, wxID_ANY, sName)
{
    m_Canvas = new cCanvas(this);
}

cEditorFrame::~cEditorFrame()
{
    delete[] m_pSprite;
}

bool cEditorFrame::New(int r, int c)
{
    delete[] m_pSprite;
    m_pSprite = new unsigned char[r * c]{0};
    m_Canvas->SetSpriteData(r, c, m_pSprite);
    sprBase = olcSprite(c, r);

    return false;
}

void cEditorFrame::SetCanvasPixelSize(int p)
{
    m_Canvas->SetPixelSize(p);
}

void cEditorFrame::SetColour(int c)
{
    m_Canvas->SetColor(c);
}