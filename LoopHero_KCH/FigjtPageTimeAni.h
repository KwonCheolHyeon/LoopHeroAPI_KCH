#pragma once
#include "chGameObject.h"
#include "chAnimator.h"
namespace ch {
	class Image;
	class FigjtPageTimeAni : public GameObject
	{
	public:
		FigjtPageTimeAni();
		~FigjtPageTimeAni();

		virtual void Tick() override;
		virtual void Render(HDC hdc) override;


	private:
		Image* mImage;
		Animator* mAnimator;
		float mTime;

	};
}
