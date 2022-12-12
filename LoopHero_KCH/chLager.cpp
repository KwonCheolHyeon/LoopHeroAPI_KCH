#include "chLager.h"
#include "chSceneManager.h"
#include "chScene.h"
#include "chResources.h"
#include "chImage.h"
#include "chAnimator.h"

namespace ch
{
	Lager::Lager()
	{
		SetName(L"Lager");
		SetPos({ 750, 437.5f });
		SetScale({ 5.0f, 5.0f });

		mAnimator = new Animator();
		mAnimator->CreateAnimations(L"..\\Resources\\loophero\\Map\\LagerAni3", L"LagerIdle");
		mAnimator->Play(L"LagerIdle", true);
		AddComponent(mAnimator);
	}
	Lager::~Lager()
	{
	}

	void Lager::Tick()
	{
		GameObject::Tick();

		Vector2 pos = GetPos();

		SetPos(pos);
	}

	void Lager::Render(HDC hdc)
	{
		GameObject::Render(hdc);

		
	}

	void Lager::Idle()
	{
	}

}