#pragma once
#include "chGameObject.h"
#include "chAnimator.h"
#include "chSound.h"
namespace ch
{
	class Image;
	class titleStarBtn : public GameObject
	{
	public:
		titleStarBtn();
		~titleStarBtn();

		virtual void Tick() override;
		virtual void Render(HDC hdc) override;
		virtual void OnCollisionEnter(Collider* other);
		virtual void OnCollisionStay(Collider* other);
		virtual void OnCollisionExit(Collider* other);
		
	private:
		Vector2 mScreenPos;
		Image* mImage;
		Animator* mAnimator;
		float mTime;
		float imageLiveTime;
		Sound* chSound;
	};

}
