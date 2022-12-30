#include "UIGameObject.h"
#include "chTime.h"
#include "chSceneManager.h"
#include "chInput.h"
#include "chMissile.h"
#include "chScene.h"
#include "chImage.h"
#include "chResources.h"
#include "chAnimator.h"
#include "chCollider.h"
#include "chCamera.h"
#include "chBackPack.h"
#include "chUIManager.h"

namespace ch
{
	UIGameObject::UIGameObject()
	{
		SetPos({ 500.0f, 200.0f });
		SetScale({ 1.0f, 1.0f });



		if (mImage == nullptr)
		{
			mImage = Resources::Load<Image>(L"Player", L"..\\Resources\\Image\\link.bmp");
		}

		mAnimator = new Animator(Animator::Mode::UIGameObject);
		//mAnimator->CreateAnimations(L"..\\Resources\\Animations\\Player\\Idle"
		//	, L"PlaneIdle");


		mAnimator->CreateAnimation(L"Idle", mImage
			, Vector2(0.0f, 0.0f), Vector2(120.0f, 130.0f)
			, Vector2(5.0f, -20.0f), 3, 0.1f);

		mAnimator->CreateAnimation(L"MoveDown", mImage
			, Vector2(0.0f, 520.0f), Vector2(120.0f, 130.0f)
			, Vector2(5.0f, -20.0f), 10, 0.1f);
		mAnimator->CreateAnimation(L"MoveLeft", mImage
			, Vector2(0.0f, 650.0f), Vector2(120.0f, 130.0f)
			, Vector2(5.0f, -20.0f), 10, 0.1f);
		mAnimator->CreateAnimation(L"MoveUp", mImage
			, Vector2(0.0f, 780.0f), Vector2(120.0f, 130.0f)
			, Vector2(5.0f, -20.0f), 10, 0.1f);
		mAnimator->CreateAnimation(L"MoveRight", mImage
			, Vector2(0.0f, 910.0f), Vector2(120.0f, 130.0f)
			, Vector2(5.0f, -20.0f), 10, 0.1f);

		mAnimator->Play(L"Idle", true);

		AddComponent(mAnimator);
	}
	UIGameObject::~UIGameObject()
	{
	}
	void UIGameObject::Tick()
	{
		GameObject::Tick();
	}
	void UIGameObject::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
}
