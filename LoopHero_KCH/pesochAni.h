#pragma once
#include "chGameObject.h"
#include "chAnimator.h"
namespace ch {

	class Image;
	class pesochAni : public GameObject
	{

	public:
		pesochAni();
		~pesochAni();

		virtual void Tick() override;
		virtual void Render(HDC hdc) override;


	private:
		Image* mImage;
		Animator* mAnimator;
	


	};
}
