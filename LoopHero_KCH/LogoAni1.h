#pragma once
#include "chGameObject.h"
#include "chAnimator.h"

namespace ch {
	class Animator;
	class Image;
	class LogoAni1 : public GameObject
	{
	public:
		LogoAni1();
		~LogoAni1();

		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

	private:
		Image* mImage;
		Animator* mAnimator;
		float mTime;


	};
}

