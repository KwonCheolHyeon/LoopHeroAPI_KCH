#include "titleStarBtn.h"
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
	titleStarBtn::titleStarBtn()
	{
		SetName(L"StartBTN");
		SetPos({ 1600 / 2, 300 / 2 });
		SetScale({ 3.0f, 3.0f });

		mAnimator = new Animator();
		mAnimator->CreateAnimations(L"..\\Resources\\loophero\\TitleScene\\btn\\start", L"StartBTN");

		AddComponent(mAnimator);
	}
	titleStarBtn::~titleStarBtn()
	{
	}
	void titleStarBtn::Tick()
	{
		GameObject::Tick();

		Vector2 pos = GetPos();

		SetPos(pos);
	}
	void titleStarBtn::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
}