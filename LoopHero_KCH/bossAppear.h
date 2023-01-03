#pragma once
#include "TileMapObject.h"
#include "chAnimator.h"
#include "chComponent.h"

namespace ch
{
	class Image;
	class bossAppear : public GameObject
	{
	public:
		bossAppear();
		bossAppear(Vector2 pos);
		~bossAppear();


		virtual void Tick() override;
		virtual void Render(HDC hdc) override;
	public:
		void Idle();
	private:
		Image* mImage;
		Animator* mAnimator;
		Vector2 lagerOffset = { 15.0f,15.0f };


	};

}

