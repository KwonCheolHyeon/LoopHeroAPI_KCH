#include "Slime.h"
#include "chTime.h"
#include "chSceneManager.h"
#include "chInput.h"
#include "chMissile.h"
#include "chScene.h"
#include "chImage.h"
#include "chResources.h"
#include "chAnimator.h"
#include "chCollider.h"

namespace ch
{
	Slime::Slime()
	{
		SetName(L"Monster");
		SetPos({ 1600 / 2, 300 / 2 });
		SetScale({ 3.0f, 3.0f });

		if (mImage == nullptr)
		{
			mImage = Resources::Load<Image>(L"Monster", L"..\\Resources\\loophero\\monster\\Slime\\idle\\s_slime_idle_0.bmp");
		}
		mAnimator = new Animator();
		mAnimator->CreateAnimations(L"..\\Resources\\loophero\\monster\\Slime\\idle", L"SlimeIdle");
		mAnimator->CreateAnimations(L"..\\Resources\\loophero\\monster\\Slime\\attack", L"Slimeattack", { 2,2 }, 0.3f);
		mAnimator->CreateAnimations(L"..\\Resources\\loophero\\monster\\Slime\\hurt", L"SlimeHurt", { 2,2 }, 0.3f);
		mAnimator->CreateAnimations(L"..\\Resources\\loophero\\monster\\Slime\\death", L"SlimeDeath", { 2,2 }, 0.3f);

		mAnimator->Play(L"SlimeIdle", true);
		AddComponent(mAnimator);
	}

	Slime::~Slime()
	{

	}

	void Slime::Tick()
	{
		GameObject::Tick();

		Vector2 pos = GetPos();

		SetPos(pos);

		if (KEY_DOWN(eKeyCode::Q))
		{
			mAnimator->Play(L"SlimeIdle", true);

		}
		if (KEY_DOWN(eKeyCode::W))
		{
			mAnimator->Play(L"Slimeattack", true);
		}
		if (KEY_DOWN(eKeyCode::E))
		{
			mAnimator->Play(L"SlimeHurt", true);
		}
		if (KEY_DOWN(eKeyCode::R))
		{
			mAnimator->Play(L"SlimeDeath", true);
		}

	}

	void Slime::Render(HDC hdc)
	{
		

		GameObject::Render(hdc);
	}

}
