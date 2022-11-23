#pragma once
#include "chGameObject.h"
#include "chAnimator.h"
namespace ch
{
	class Image;
	class Slime : public GameObject
	{
	public:
		Slime();
		~Slime();

		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

		
	private:
		Image* mImage;
		Animator* mAnimator;
		float mTime;
	};

}