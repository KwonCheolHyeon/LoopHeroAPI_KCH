#pragma once
#include "chGameObject.h"
#include "chAnimator.h"
#include "MonsterStat.h"
#include "chSound.h"
namespace ch {

	class Image;
	class Monsters : public GameObject
	{
	public:
		Monsters();
		Monsters(int monsterIndex, Vector2 position);
		~Monsters();

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

		float lichTime;
		bool lichTimeCheck;
	private: //����
		MonsterHP mHP;
		MonsterATT mATT;
		MonsterDEF mDEF;
		MonsterSPD mSPD;

		MonsteritemRelv mITEM;
		double attSpdChek;//�ʴ� ���� �ӵ�

	private:
		Sound* monsterAttack_sound;
		Sound* fightLich_Sound;
		Sound* deathLich_Sound;
	};
}
