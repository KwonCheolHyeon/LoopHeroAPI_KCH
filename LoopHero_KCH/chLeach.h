#pragma once
#include "chGameObject.h"
#include "chAnimator.h"
#include "MonsterStat.h"


namespace ch
{
	class Image;
	class Leach : public GameObject
	{
	public:
		Leach();
		Leach(int monsterIndex, Vector2 position);
		~Leach();

		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

	public:

		void mAttack();
		void mTakeDamage(double damage);
		double mCalcDef(double damage);
		void mItems(); //아이템 나오는 함수
		void checkHp();

		int GetHp() { return mHP.nowHP; }

		bool fullItemCheck();
	private:
		Image* mImage;
		Animator* mAnimator;
		float mTime;
		int MonsterIndex;

		bool death;
	private: //스텟
		MonsterHP mHP;
		MonsterATT mATT;
		MonsterDEF mDEF;
		MonsterSPD mSPD;

		MonsteritemRelv mITEM;
		double attSpdChek;//초당 공격 속도
	};

}



