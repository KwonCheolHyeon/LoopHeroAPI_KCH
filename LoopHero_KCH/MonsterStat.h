#pragma once
namespace ch {

	struct MonsterHP//체력    
	{
		int baseHp;
		int nowHP;
	};
	struct MonsterATT//공격력  ///// attack()
	{
		double baseStr;
		double nowStr;
	
	};
	struct MonsterDEF // 방어력   // takeDamage()
	{
		double baseDef;
		double nowDef;
	};

	struct MonsterSPD // 스피드   // takeDamage()
	{
		double spd;

	};

	struct MonsterEVADE // 회피율   // takeDamage()
	{
		int evade;

	};

	struct MonsterREGEN // 체젠   // takeDamage()
	{
		double regen;

	};

	struct MonsteritemRelv
	{
		int itemChance; //아이템 나올 확률	
		int itemTier; // 아이템 티어
		int itemBounslevel; //아이템 보너스 레벨
	};
}
