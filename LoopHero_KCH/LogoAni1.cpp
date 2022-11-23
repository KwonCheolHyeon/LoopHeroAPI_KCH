#include "LogoAni1.h"

namespace ch 
{
	LogoAni1::LogoAni1()
	{
		SetName(L"Monster");
		SetPos({ 1600 / 2, 300 / 2 });
		SetScale({ 3.0f, 3.0f });

		mAnimator = new Animator();
		mAnimator->CreateAnimations(L"..\\Resources\\loophero\\TitleScene\\intro_test2", L"Logo1", {1,1}, 0.1f);
		mAnimator->Play(L"Logo1", false);
		AddComponent(mAnimator);

	}

	LogoAni1::~LogoAni1()
	{
	}

	void LogoAni1::Tick()
	{
		GameObject::Tick();

		Vector2 pos = GetPos();

		SetPos(pos);
	}

	void LogoAni1::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

}

