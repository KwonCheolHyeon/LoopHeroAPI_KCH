#pragma once
#include "chGameObject.h"
namespace ch
{
	class Animator;
	class Image;
	class UIGameObject : public GameObject
	{
	public:
		UIGameObject();
		~UIGameObject();

		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

	private:
		Animator* mAnimator;
		Image* mImage;
	};

}
