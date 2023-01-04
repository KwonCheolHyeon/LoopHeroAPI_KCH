#include "chHUD.h"
#include "chImage.h"
#include "chHUD.h"
#include "chPlayer.h"
#include "chAnimator.h"
#include "chResources.h"

namespace ch
{
	HUD::HUD(eUIType type)
		: UiBase(type)
	{
		//Image* charcterImg = Resources::Load<Image>(L"Player", L"..\\Resources\\Image\\link.bmp");

		//mAnimator = new Animator();
		//mAnimator->CreateAnimation(L"Idle", charcterImg
		//	, Vector2(0.0f, 0.0f), Vector2(120.0f, 130.0f)
		//	, Vector2(5.0f, -20.0f), 3, 0.1f);

		//mAnimator->Play(L"Idle", true);
		//mAnimator->SetOwner(mRectObject);
		//
	}
	HUD::~HUD()
	{
	}
	void HUD::OnInit()
	{
	}
	void HUD::OnActive()
	{
	}
	void HUD::OnInActive()
	{

	}
	void HUD::OnTick()
	{
	}

	void HUD::OnRender(HDC hdc)
	{
		if (mImage == nullptr)
			return;

		if (mTarget == nullptr)
			return;
		

	}

	void HUD::OnClear()
	{

	}
}