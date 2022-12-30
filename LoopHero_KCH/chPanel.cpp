#include "chPanel.h"
#include "chImage.h"

namespace ch {
    Panel::Panel(eUIType type)
        : UiBase(type)
    {
    }

    Panel::~Panel()
    {
    }

    void Panel::OnInit()
    {
    }

    void Panel::OnActive()
    {

    }

    void Panel::OnInActive()
    {

    }

    void Panel::OnTick()
    {

    }

    void Panel::OnRender(HDC hdc)
    {

        TransparentBlt(hdc, (int)mScreenPos.x, (int)mScreenPos.y, mImage->GetWidth(), mImage->GetHeight()
            , mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
            , RGB(255, 0, 255));

    }

    void Panel::OnClear()
    {

    }
}