#pragma once
#include "chGameObject.h"
#include "chAnimator.h"

namespace ch 
{
	class Image;
	class eyeOfSight : public GameObject
	{
	public:
		eyeOfSight();
		~eyeOfSight();

		virtual void Tick() override;
		virtual void Render(HDC hdc) override;


	private:
		Image* mImage;
		Animator* mAnimator;
	};
}

