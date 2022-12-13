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
		WarriorMini(Vector2 pos);
		~WarriorMini();

		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

		void chMove();

	public:
		int loopTIme = 1; ////////현재 루프 UI 에 넣어도 될듯///////
		int gameSpeed = 1;


	public:
		void roadCheck(int dir, Vector2 pos);

	private:
		double distanceOne; // 한칸 거리 한칸 만큼 이동 해야 하기 때문
		Image* mImage;
		Animator* mAnimator;
		Vector2 miniOffset ={25.0f,25.0f};
		double miniMoveSpeed;

		bool roadCk = true;
		
	};
}