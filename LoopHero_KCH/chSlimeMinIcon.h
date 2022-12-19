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

		void mMonsterCount();
	private:
		Image* mImage;
		Animator* mAnimator;
		Vector2 miniOffset[6];
		
	};
}
