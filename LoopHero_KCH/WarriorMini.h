#pragma once
#include "chGameObject.h"
#include "chAnimator.h"

namespace ch
{

	class Image;
	class WarriorMini : public GameObject
	{
	public:
		WarriorMini();
		~WarriorMini();

		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

		void chMove();
		
	public:
		int loopTIme = 1; ////////현재 루프 UI 에 넣어도 될듯///////
		int gameSpeed = 1;


	private:
		Image* mImage;
		Animator* mAnimator;
	};
}