#pragma once
#include "TileMapObject.h"
#include "chAnimator.h"
#include "chComponent.h"

namespace ch 
{
	class Image;
	class Lager : public GameObject
	{
	public:
		Lager();
		~Lager();

		
		virtual void Tick() override;
		virtual void Render(HDC hdc) override;
	public:
		void Idle();
	private:
		Image* mImage;
		Animator* mAnimator;


	};

}

