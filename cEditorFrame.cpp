#include "cEditorFrame.h"

wxBEGIN_EVENT_TABLE(cEditorFrame, wxMDIChildFrame)
#ifdef _WIN32
    EVT_SLIDER(20001, cEditorFrame::OnZoomChange)
#endif
        wxEND_EVENT_TABLE();

cEditorFrame::cEditorFrame(wxMDIParentFrame *parent, wxString sName)
    : wxMDIChildFrame(parent, wxID_ANY, sName)
{
    m_Canvas = new cCanvas(this);
#ifdef _WIN32
    m_StatusBar = this->CreateStatusBar(2);                    // * 2 regions
    m_StatusBar->SetStatusText(wxString("Frame"), 1);          // * text, region
    m_ZoomSlider = new wxSlider(m_StatusBar, 20001, 8, 1, 32); // * parent, ID, default value, min, max
#endif
}

cEditorFrame::~cEditorFrame()
{
    delete[] m_pSprite;
    delete sprBase;
}

bool cEditorFrame::New(int r, int c)
{
    delete[] m_pSprite;
    m_pSprite = new unsigned char[r * c]{0};
    m_Canvas->SetSpriteData(r, c, m_pSprite);
    if (sprBase)
        delete sprBase;
    sprBase = new olcSprite(c, r);

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

bool cEditorFrame::Open(wxString sFileName)
{
    if (sprBase != nullptr)
        delete sprBase;
    sprBase = new olcSprite();

    if (!sprBase->Load(sFileName.wc_str()))
        return false;

    delete[] m_pSprite;
    m_pSprite = new unsigned char[sprBase->nWidth * sprBase->nHeight]{0};

    for (int i = 0; i < sprBase->nWidth; i++)
    {
        for (int j = 0; j < sprBase->nHeight; j++)
        {
            unsigned short glyph = sprBase->GetGlyph(i, j);
            short colour = sprBase->GetColour(i, j);
            if (glyph == L' ')
                m_pSprite[j * sprBase->nWidth + i] = 16;
            else
                m_pSprite[j * sprBase->nWidth + i] = colour & 0x000F;
        }
    }
    m_Canvas->SetSpriteData(sprBase->nHeight, sprBase->nWidth, m_pSprite);
    return true;
}

bool cEditorFrame::Save(wxString sFileName)
{
    for (int i = 0; i < sprBase->nWidth; i++)
    {
        for (int j = 0; j < sprBase->nHeight; j++)
        {
            short colour = m_pSprite[j * sprBase->nWidth + i];
            if (colour == 16)
            {
                sprBase->SetColour(i, j, 0);
                sprBase->SetGlyph(i, j, L' ');
            }
            else
            {
                sprBase->SetColour(i, j, colour);
                sprBase->SetGlyph(i, j, 0x2588);
            }
        }
    }
    return sprBase->Save(sFileName.wc_str());
}

#ifdef _WIN32
void cEditorFrame::OnZoomChange(wxCommandEvent &evt)
{
    m_StatusBar->SetStatusText(wxString("Zoom: ") << m_ZoomSlider->GetValue(), 1); // * text, region
    SetCanvasPixelSize(m_ZoomSlider->GetValue());
    evt.Skip();
}
#endif