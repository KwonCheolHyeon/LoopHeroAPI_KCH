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
		void mItems(); //������ ������ �Լ�
		void checkHp();

		int GetHp() { return mHP.nowHP; }

		bool fullItemCheck();
	private:
		Image* mImage;
		Animator* mAnimator;
		float mTime;
		int MonsterIndex;

		bool death;
	private: //����
		MonsterHP mHP;
		MonsterATT mATT;
		MonsterDEF mDEF;
		MonsterSPD mSPD;

		MonsteritemRelv mITEM;
		double attSpdChek;//�ʴ� ���� �ӵ�
	};

}



