#include "cEditorFrame.h"

wxBEGIN_EVENT_TABLE(cEditorFrame, wxMDIChildFrame)
    EVT_SLIDER(20001, cEditorFrame::OnZoomChange)
        wxEND_EVENT_TABLE();

cEditorFrame::cEditorFrame(wxMDIParentFrame *parent, wxString sName)
    : wxMDIChildFrame(parent, wxID_ANY, sName)
{
    m_Canvas = new cCanvas(this);

    m_StatusBar = this->CreateStatusBar(2, wxSTB_DEFAULT_STYLE, wxID_ANY); // * 2 regions
    m_ZoomSlider = new wxSlider(m_StatusBar, 20001, 8, 1, 32);             // * parent, ID, default value, min, max
    m_StatusBar->SetStatusText(wxString("Zoom: ") << m_ZoomSlider->GetValue(), 1); // * text, region
}

cEditorFrame::~cEditorFrame()
{
}

void cEditorFrame::OnZoomChange(wxCommandEvent &evt)
{
    m_StatusBar->SetStatusText(wxString("Zoom: ") << m_ZoomSlider->GetValue(), 1); // * text, region
    m_Canvas->SetPixelSize(m_ZoomSlider->GetValue());
    evt.Skip();
}