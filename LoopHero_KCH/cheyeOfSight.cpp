#include "cheyeOfSight.h"
#include "chSceneManager.h"
#include "chInput.h"
#include "chScene.h"
#include "chImage.h"
#include "chResources.h"
#include "chAnimator.h"
#include "chObject.h"

namespace ch
{

	eyeOfSight::eyeOfSight()
	{
		SetName(L"FightTime");
		SetPos({ 497, 10 });
		SetScale({ 2.5f, 2.5f });

		mAnimator = new Animator();
		mAnimator->CreateAnimations(L"..\\Resources\\loophero\\MainGame\\eyeofspace", L"eyeofsightStart", { 1,1 }, 0.2f);
		mAnimator->Play(L"eyeofsightStart", true);
		AddComponent(mAnimator);
	}

	eyeOfSight::~eyeOfSight()
	{
	}

	void eyeOfSight::Tick()
	{
		GameObject::Tick();


		Vector2 pos = GetPos();

		SetPos(pos);
	}

	void eyeOfSight::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}



}

