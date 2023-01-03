#include "bossAppear.h"
#include "chSceneManager.h"
#include "chScene.h"
#include "chResources.h"
#include "chImage.h"
#include "chAnimator.h"


namespace ch
{
	bossAppear::bossAppear()
	{
		SetName(L"Lager");

		SetScale({ 5.0f, 5.0f });

		mAnimator = new Animator();
		mAnimator->CreateAnimations(L"..\\Resources\\loophero\\Boss\\appear", L"appearLeach");
		mAnimator->Play(L"LagerIdle", true);
		AddComponent(mAnimator);
	}
	bossAppear::bossAppear(Vector2 pos)
	{
		pos = lagerOffset + pos;
		SetName(L"appleach");
		SetPos(pos);
		SetScale({ 5.0f, 5.0f });


		mAnimator = new Animator();

		mAnimator->CreateAnimations(L"..\\Resources\\loophero\\Boss\\appear", L"appearLeach", Vector2(0,-115));

		mAnimator->Play(L"appearLeach", false);

		AddComponent(mAnimator);
	}
	bossAppear::~bossAppear()
	{
	}
	void bossAppear::Tick()
	{
		GameObject::Tick();

		Vector2 pos = GetPos();

		SetPos(pos);
	}
	void bossAppear::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void bossAppear::Idle()
	{
	}
}