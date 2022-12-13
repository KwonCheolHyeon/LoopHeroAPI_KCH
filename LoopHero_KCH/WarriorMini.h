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
		int loopTIme = 1; ////////���� ���� UI �� �־ �ɵ�///////
		int gameSpeed = 1;


	public:
		void roadCheck(int dir, Vector2 pos);

	private:
		double distanceOne; // ��ĭ �Ÿ� ��ĭ ��ŭ �̵� �ؾ� �ϱ� ����
		Image* mImage;
		Animator* mAnimator;
		Vector2 miniOffset ={25.0f,25.0f};
		double miniMoveSpeed;

		bool roadCk = true;
		
	};
}