#include "WarriorMini.h"
#include "chSceneManager.h"
#include "chInput.h"
#include "chScene.h"
#include "chImage.h"
#include "chResources.h"
#include "chAnimator.h"
#include "chObject.h"

namespace ch 
{
   

    WarriorMini::WarriorMini()
    {
        SetName(L"WarriorMini");
        SetPos({ 1600 / 2, 300 / 2 });
        SetScale({ 3.0f, 3.0f });

        if (mImage == nullptr)
        {
            mImage = Resources::Load<Image>(L"Warrior", L"..\\Resources\\loophero\\character\\warrior\\warrior_00.bmp");
        }

        mAnimator = new Animator();
        mAnimator->CreateAnimations(L"..\\Resources\\loophero\\character\\Warrior_Icon", L"Warrior_Idle");
        mAnimator->Play(L"Warrior_Idle", true);
        AddComponent(mAnimator);
    }
    WarriorMini::~WarriorMini()
    {

    }
    void WarriorMini::Tick()
    {
        GameObject::Tick();

        Vector2 pos = GetPos();

        SetPos(pos);

    }
    void WarriorMini::Render(HDC hdc)
    {
        GameObject::Render(hdc);
    }
    void WarriorMini::chMove()
    {

    }
}