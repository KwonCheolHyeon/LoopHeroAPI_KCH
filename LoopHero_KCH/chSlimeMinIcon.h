#pragma once
#include "chGameObject.h"
#include "chAnimator.h"

namespace ch 
{
	class Image;
	class SlimeMinIcon : public GameObject
	{
	public:
		SlimeMinIcon();
		SlimeMinIcon(Vector2 pos);
		~SlimeMinIcon();

		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

		
	private:
		Image* mImage;
		Animator* mAnimator;
		Vector2 miniOffset[6];

		int MonsterSetPos(Vector2 pos);
		Vector2 InMapPosCalc(Vector2 pos);
		
	};
}
