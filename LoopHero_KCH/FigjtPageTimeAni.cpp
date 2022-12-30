#include "FigjtPageTimeAni.h"
#include "chTime.h"
#include "chSceneManager.h"
#include "chInput.h"
#include "chScene.h"
#include "chImage.h"
#include "chResources.h"
#include "chAnimator.h"
#include "chObject.h"
#include "pesochAni.h"
namespace ch 
{
	FigjtPageTimeAni::FigjtPageTimeAni()
	{
		SetName(L"FightTime");
		SetPos({ 610, 120 });
		SetScale({ 2.5f, 2.5f });

		mAnimator = new Animator();
		mAnimator->CreateAnimations(L"..\\Resources\\loophero\\FightPage\\start", L"FightStart", {1,1},0.5f);
		mAnimator->CreateAnimations(L"..\\Resources\\loophero\\FightPage\\stop", L"FightStop", { 1,1 }, 0.5f);
		mAnimator->CreateAnimations(L"..\\Resources\\loophero\\FightPage\\openIdle", L"openIdle", { 1,1 }, 0.5f);
		mAnimator->CreateAnimations(L"..\\Resources\\loophero\\FightPage\\closeIdle", L"closeIdle", { 1,1 }, 0.5f);
		mAnimator->Play(L"openIdle", false);
		AddComponent(mAnimator);
		ch::object::Instantiate<pesochAni>(eColliderLayer::PlayerMonster);
		
	}

	FigjtPageTimeAni::~FigjtPageTimeAni()
	{

	}
	void FigjtPageTimeAni::Tick()
	{
		GameObject::Tick();


		Vector2 pos = GetPos();

		SetPos(pos);
		if (KEY_DOWN(eKeyCode::U))
		{
			mAnimator->Play(L"FightStart", false);
		
			
		}
		if (KEY_DOWN(eKeyCode::I))
		{
			mAnimator->Play(L"FightStop",false);//먼가 아래로 내려감
			
		}
		if (KEY_DOWN(eKeyCode::O))
		{
			mAnimator->Play(L"openIdle", false);
			
		}
		if (KEY_DOWN(eKeyCode::P))
		{
			mAnimator->Play(L"closeIdle", true);
			
		}


	}
	void FigjtPageTimeAni::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
}

