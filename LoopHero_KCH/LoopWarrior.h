#pragma once
#include "chGameObject.h"
#include "PlayerStat.h"
#include "chSound.h"
namespace ch {
	
	class Animator;
	class Image;
	class LoopWarrior : public GameObject
	{
	public:
		LoopWarrior();
		LoopWarrior(Vector2 pos);
		~LoopWarrior();

		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

		void IdleImage(HDC hdc);

		// �÷��̾� ����, ������ �ޱ�, ȸ��, ü��
		
		void EndFightCheck();
		void Attack();
		void takeDamage(double damage);
		double calcDEF(double damage);
		void pRegenHP();
		void checkStat();
		void randStat();//���� �����ִ� ��
		void ppLevelUp(int mEXP);//������ ����
		double pDefSelect();
		int pAttSelect();

		bool pAvoid(); //ȸ��
		bool pCritical(); //ũ��Ƽ��
		bool pCounterAtt(); //ī���� ����

		static float CHmaxHp;
		static float CHnowHp;
	public:
		int loopTIme = 1; ////////���� ���� UI �� �־ �ɵ�///////
		static int gameSpeed;
		
		int monsterCount;

		static bool FightDone;
	private:
		Image* mImage;
		Animator* mAnimator;
		double playerRegenTime = 0; //ü�� �ð�
		double playerAttSpd = 0;

		bool plive;//����ִ���?
		bool oneFight;

	private: //����
		HP pHp; // hp
		RegenHP pRegen; // �ʴ� ȸ��
		DEF pDef; // ����
		ATT pAtt; //���ݷ�
		EVADE pEvade; // ȸ�� Ȯ��
		COUNTER pCounterAtk; // ī���� ���� Ȯ��
		CRIT_PERC pCriticalPer;//ũ��Ƽ�� Ȯ��
		LevelUp pExp; //������ ����ġ ����
		AttSpd pSpd;


	private://����
		Sound* heroAttk_Sound;
	};
}
