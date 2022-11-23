#include "pesochAni.h"
#include "chSceneManager.h"
#include "chInput.h"
#include "chScene.h"
#include "chImage.h"
#include "chResources.h"
#include "chAnimator.h"
#include "chObject.h"
namespace ch 
{
	pesochAni::pesochAni()
	{
		SetName(L"FightTime");
		SetPos({ 650, 140 });
		SetScale({ 2.0f, 2.0f });

		mAnimator = new Animator();
		mAnimator->CreateAnimations(L"..\\Resources\\loophero\\FightPage\\Pesoch\\Pesoch", L"OpenPesoch", { 1,1 }, 0.6f);
		mAnimator->CreateAnimations(L"..\\Resources\\loophero\\FightPage\\Pesoch\\NoPesoch", L"ClosePesoch");
		AddComponent(mAnimator);
	}

	pesochAni::~pesochAni()
	{
		
	}

	void pesochAni::Tick()
	{
	
		GameObject::Tick();


		Vector2 pos = GetPos();

		SetPos(pos);
		if (KEY_DOWN(eKeyCode::P))
		{
			mAnimator->Play(L"OpenPesoch", true);
		}
		if (KEY_DOWN(eKeyCode::O))
		{
			mAnimator->Play(L"ClosePesoch", false);
		}
		
	}

	void pesochAni::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

}