#pragma once

namespace ch {

	struct HP//체력    
	{
		double minHp = 280;
		double wepHp = 0;
		double maxHp ;//
		double nowHp;
		double MagicHp=0;
	};
	struct ATT//공격력  ///// attack()
	{
		int minAtt;
		int maxAtt;
		int nowAtt;
	};
	struct DEF // 방어력   // takeDamage()
	{
		int minDef;
		int maxDef;
		int nowDef;
	};
	struct TrueDMG //순수데미지(방어력 무시)  ///// attack()
	{
		int Truedmg;
	};
	struct ATTSPEED   ///// attack()
	{
		int attSpeed = 4;
	};
	struct COUNTER //반격 확률
	{
		
		int wepCounter=0;//아이템 카운터공격 확률
		int perCounter = wepCounter;//최종 카운터 공격 확률
	};
	struct RegenHP //체젠
	{
		double regenHP;
	};

	struct EVADE //회피 확률   // takeDamage()
	{
		int wepEvade=0;//아이템 회피 확률
		int minEvade = 8;
		int perEvade = wepEvade + minEvade; // 최종 회피 확률
	};

	struct VAMP //피흡 ///// attack()
	{
		int wepVamp=0;
		int minVamp = 8;
		int perVamp = wepVamp + minVamp;
	};
	struct CRIT_CHAN //크리티컬 데미지  ///// attack()
	{
	//2배로 할 생각
	
	};
	struct CRIT_PERC //크리티컬 확률  ///// attack()
	{
		int wepCRITPERC = 0; // 아이템 크리티컬 확률
		int minCRITPERC = 0; // 최소 크리티컬 확률
		int perCRITPERC = wepCRITPERC + minCRITPERC; // 전체 크리티컬 확률
	};
	struct RETDMG //광역 데미지  ///// attack()
	{
		int AllDmg;
	};
	
	struct LevelUp //레벨업 관련
	{
		int level=1;
		int maxExp = 200;
		int exp=0;
	};
	
	


}

