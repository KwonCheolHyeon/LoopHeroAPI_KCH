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
#include "chSound.h"
#include "chSoundManager.h"

namespace ch
{
	titleStarBtn::titleStarBtn()
	{
		SetName(L"StartBTN");
		SetPos({ 720,-950+420 });
		SetScale({ 2.5f, 2.5f });

		mAnimator = new Animator();
		mAnimator->CreateAnimations(L"..\\Resources\\loophero\\BTN\\startBtn", L"StartBTN");
		mAnimator->CreateAnimations(L"..\\Resources\\loophero\\BTN\\idle", L"StartIdleBTN");
		mAnimator->Play(L"StartIdleBTN", false);
		AddComponent(mAnimator);

		Collider* collider = new Collider();
		AddComponent(collider);
		collider->SetOffset(Vector2(70, 20));
		collider->SetScale(Vector2(97*2.5f, 17*2.5f));

		chSound = Resources::Load<Sound>(L"intro", L"..\\Resources\\sound\\snd_intro.wav");
		chSound->Play(false);
	}
	titleStarBtn::~titleStarBtn()
	{
	}
	void titleStarBtn::Tick()
	{
		GameObject::Tick();

		Vector2 pos = GetPos();

		imageLiveTime += Time::DeltaTime();
		if (imageLiveTime >= 2.0f && imageLiveTime <= 4.7f)
		{
			pos.y += Time::DeltaTime() * 350;
		}


		SetPos(pos);

	}
	void titleStarBtn::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void titleStarBtn::OnCollisionEnter(Collider* other)
	{
		mAnimator->Play(L"StartBTN", false);
	}

	void titleStarBtn::OnCollisionStay(Collider* other)
	{
		if (KEY_DOWN(eKeyCode::LBTN))
		{
			SceneManager::ChangeScene(eSceneType::Play);
			chSound->Stop(true);
		}
	}

	void titleStarBtn::OnCollisionExit(Collider* other)
	{
		mAnimator->Play(L"StartIdleBTN", false);
	}
}