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
		Lager(Vector2 pos);
		~Lager();

		
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

