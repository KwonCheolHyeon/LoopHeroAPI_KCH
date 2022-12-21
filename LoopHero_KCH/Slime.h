#pragma once
#include "chGameObject.h"
#include "chAnimator.h"
#include "MonsterStat.h"

namespace ch
{
	class Image;
	class Slime : public GameObject
	{
	public:
		Slime();
		Slime(Vector2 pos);
		~Slime();

		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

	public:
		void mSetTarget();
		void mAttack();
		void takeDamage(double damage);
		double calcDEF(double damage);
		void ITEMs();

	private:
		Image* mImage;
		Animator* mAnimator;
		float mTime;

	private: //스텟
		MonsterHP mHP;
		MonsterATT mATT;
		MonsterDEF mDEF;
		MonsterSPD mSPD;

		MonsteritemRelv mITEM;
		double attSpdChek;//초당 공격 속도
	};

}