#pragma once
namespace ch {

	struct MonsterHP//ü��    
	{
		int baseHp;
		int nowHP;
	};
	struct MonsterATT//���ݷ�  ///// attack()
	{
		double baseStr;
		double nowStr;
	
	};
	struct MonsterDEF // ����   // takeDamage()
	{
		double baseDef;
		double nowDef;
	};

	struct MonsterSPD // ���ǵ�   // takeDamage()
	{
		double spd;

	};

	struct MonsterEVADE // ȸ����   // takeDamage()
	{
		int evade;

	};

	struct MonsterREGEN // ü��   // takeDamage()
	{
		double regen;

	};

	struct MonsteritemRelv
	{
		int itemChance; //������ ���� Ȯ��	
		int itemTier; // ������ Ƽ��
		int itemBounslevel; //������ ���ʽ� ����
	};
}
