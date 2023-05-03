#pragma once

#include <wx/wx.h>
#include <fstream>

#include "cCanvas.h"

// * class from Console Game Engine
// * https://github.com/OneLoneCoder/Javidx9/tree/master/ConsoleGameEngine
class olcSprite
{
public:
    olcSprite()
    {
    }

    olcSprite(int w, int h)
    {
        Create(w, h);
    }

    olcSprite(std::wstring sFile)
    {
        if (!Load(sFile))
            Create(8, 8);
    }

    ~olcSprite()
    {
        if (m_Glyphs != nullptr)
            delete[] m_Glyphs;
        if (m_Colours != nullptr)
            delete[] m_Colours;
    }

    int nWidth = 0;
    int nHeight = 0;

private:
    unsigned short *m_Glyphs = nullptr;
    short *m_Colours = nullptr;

    void Create(int w, int h)
    {
        nWidth = w;
        nHeight = h;
        m_Glyphs = new unsigned short[w * h];
        m_Colours = new short[w * h];
        for (int i = 0; i < w * h; i++)
        {
            m_Glyphs[i] = L' ';
            m_Colours[i] = 0x0000;
        }
    }

public:
    void SetGlyph(int x, int y, unsigned short c)
    {
        if (x < 0 || x >= nWidth || y < 0 || y >= nHeight)
            return;
        else
            m_Glyphs[y * nWidth + x] = c;
    }

    void SetColour(int x, int y, short c)
    {
        if (x < 0 || x >= nWidth || y < 0 || y >= nHeight)
            return;
        else
            m_Colours[y * nWidth + x] = c;
    }

    unsigned short GetGlyph(int x, int y)
    {
        if (x < 0 || x >= nWidth || y < 0 || y >= nHeight)
            return L' ';
        else
            return m_Glyphs[y * nWidth + x];
    }

    short GetColour(int x, int y)
    {
        if (x < 0 || x >= nWidth || y < 0 || y >= nHeight)
            return 0x0000;
        else
            return m_Colours[y * nWidth + x];
    }

    unsigned short SampleGlyph(float x, float y)
    {
        int sx = (int)(x * (float)nWidth);
        int sy = (int)(y * (float)nHeight - 1.0f);
        if (sx < 0 || sx >= nWidth || sy < 0 || sy >= nHeight)
            return L' ';
        else
            return m_Glyphs[sy * nWidth + sx];
    }

    short SampleColour(float x, float y)
    {
        int sx = (int)(x * (float)nWidth);
        int sy = (int)(y * (float)nHeight - 1.0f);
        if (sx < 0 || sx >= nWidth || sy < 0 || sy >= nHeight)
            return 0x0000;
        else
            return m_Colours[sy * nWidth + sx];
    }

    bool Save(std::wstring sFile)
    {

#ifdef _WIN32
        std::ofstream f(sFile.c_str(), std::ios::out | std::ios::binary);
#else
        std::string path(sFile.begin(), sFile.end());
        std::ofstream f(path.c_str(), std::ios::out | std::ios::binary);
#endif
        if (!f.is_open())
            return false;

        f.write((char *)&nWidth, sizeof(int));
        f.write((char *)&nHeight, sizeof(int));
        f.write((char *)m_Colours, sizeof(short) * nWidth * nHeight);
        f.write((char *)m_Glyphs, sizeof(unsigned short) * nWidth * nHeight);

        f.close();

        return true;
    }

    bool Load(std::wstring sFile)
    {
        if (m_Glyphs != nullptr)
            delete[] m_Glyphs;
        if (m_Colours != nullptr)
            delete[] m_Colours;
        nWidth = 0;
        nHeight = 0;

#ifdef _WIN32
        std::ifstream f(sFile.c_str(), std::ios::in | std::ios::binary);
#else
        std::string path(sFile.begin(), sFile.end());
        std::ifstream f(path.c_str(), std::ios::in | std::ios::binary);
#endif
        if (!f.is_open())
        {
            std::wcout << L"Could not load file " + sFile + L"\n";
            throw 1;
        }

        // get file data
        f.read((char *)&nWidth, sizeof(int));
        f.read((char *)&nHeight, sizeof(int));

        Create(nWidth, nHeight);

        f.read((char *)m_Colours, sizeof(short) * nWidth * nHeight);
        f.read((char *)m_Glyphs, sizeof(unsigned short) * nWidth * nHeight);

        f.close();

        return true;
    }
};

class cEditorFrame : public wxMDIChildFrame
{
public:
    cEditorFrame(wxMDIParentFrame *parent, wxString sName);
    ~cEditorFrame();

    bool New(int r, int c);

    void SetCanvasPixelSize(int p);
    void SetColour(int c);

    bool Open(wxString sFileName);
    bool Save(wxString sFileName);

private:
    cCanvas *m_Canvas = nullptr;

    olcSprite *sprBase = nullptr;
    unsigned char *m_pSprite = nullptr;

    wxDECLARE_EVENT_TABLE();
};
