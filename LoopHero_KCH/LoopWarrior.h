#pragma once
#include "chGameObject.h"
#include "PlayerStat.h"

namespace ch {
	class Animator;
	class Image;
	class LoopWarrior : public GameObject
	{
	public:
		LoopWarrior();
		~LoopWarrior();

		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

		void IdleImage(HDC hdc);

		// �÷��̾� ����, ������ �ޱ�, ȸ��, ü��
		
		void setTarget();
		void Attack();
		void takeDamage(double damage);
		double calcDEF(double damage);
		void pRegenHP();
		void checkStat();
		void randStat();//���� �����ִ� ��
		void ppLevelUp(int mEXP);//������ ����
	
		
		
		bool pAvoid(); //ȸ��
		bool pCritical(); //ũ��Ƽ��
		bool pCounterAtt(); //ī���� ����


	public:
		int loopTIme = 1; ////////���� ���� UI �� �־ �ɵ�///////
		int gameSpeed = 1;


	private:
		Image* mImage;
		Animator* mAnimator;
		double playerRegenTime = 0; //ü�� �ð�

		bool plive;//����ִ���?


	private: //����
		HP pHp; // hp
		RegenHP pRegen; // �ʴ� ȸ��
		DEF pDef; // ����
		ATT pAtt; //���ݷ�
		EVADE pEvade; // ȸ�� Ȯ��
		COUNTER pCounterAtk; // ī���� ���� Ȯ��
		CRIT_PERC pCriticalPer;//ũ��Ƽ�� Ȯ��
		LevelUp pExp; //������ ����ġ ����
	};
}
