#pragma once
#include "chGameObject.h"


namespace ch {
	class Animator;
	class Image;
	class WarriorMini : public GameObject
	{
	public:
		WarriorMini();
		~WarriorMini();

		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

		
	public:
		int loopTIme = 1; ////////���� ���� UI �� �־ �ɵ�///////
		int gameSpeed = 1;


	private:
		Image* mImage;
		Animator* mAnimator;
	};
}