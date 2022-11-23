#pragma once
#include "chGameObject.h"

namespace ch
{
	class Animator;
	class Image;
	class Player : public GameObject
	{
	public:
		Player();
		~Player();

		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

		virtual void OnCollisionEnter(Collider* other) override;
		virtual void OnCollisionStay(Collider* other) override;
		virtual void OnCollisionExit(Collider* other) override;

		void WalkComplete();

	private:
		float mSpeed;
		Image* mImage;
		Animator* mAnimator;
	};
}
