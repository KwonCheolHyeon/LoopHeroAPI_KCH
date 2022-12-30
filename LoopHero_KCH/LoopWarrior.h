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
		LoopWarrior(Vector2 pos);
		~LoopWarrior();

		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

		void IdleImage(HDC hdc);

		// 플레이어 공격, 데미지 받기, 회피, 체력
		
		void EndFightCheck();
		void Attack();
		void takeDamage(double damage);
		double calcDEF(double damage);
		void pRegenHP();
		void checkStat();
		void randStat();//범위 정해주는 거
		void ppLevelUp(int mEXP);//레벨업 관련
		double pDefSelect();
		int pAttSelect();

		bool pAvoid(); //회피
		bool pCritical(); //크리티컬
		bool pCounterAtt(); //카운터 공격


	public:
		int loopTIme = 1; ////////현재 루프 UI 에 넣어도 될듯///////
		int gameSpeed = 1;
		
		int monsterCount;

		static bool FightDone;
	private:
		Image* mImage;
		Animator* mAnimator;
		double playerRegenTime = 0; //체젠 시간
		double playerAttSpd = 0;

		bool plive;//살아있는지?
		

	private: //스텟
		HP pHp; // hp
		RegenHP pRegen; // 초당 회복
		DEF pDef; // 방어력
		ATT pAtt; //공격력
		EVADE pEvade; // 회피 확률
		COUNTER pCounterAtk; // 카운터 공격 확률
		CRIT_PERC pCriticalPer;//크리티컬 확률
		LevelUp pExp; //레벨업 경험치 관련
		AttSpd pSpd;
	};
}
