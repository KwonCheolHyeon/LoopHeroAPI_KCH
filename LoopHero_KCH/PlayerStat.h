#pragma once

namespace ch {

	struct HP//ü��    
	{
		double minHp = 280;
		double wepHp = 0;
		double maxHp ;//
		double nowHp;
		double MagicHp=0;
	};
	struct ATT//���ݷ�  ///// attack()
	{
		int minAtt;
		int maxAtt;
		int nowAtt;
	};
	struct DEF // ����   // takeDamage()
	{
		int minDef;
		int maxDef;
		int nowDef;
	};
	struct TrueDMG //����������(���� ����)  ///// attack()
	{
		int Truedmg;
	};
	struct ATTSPEED   ///// attack()
	{
		int attSpeed = 4;
	};
	struct COUNTER //�ݰ� Ȯ��
	{
		
		int wepCounter=0;//������ ī���Ͱ��� Ȯ��
		int perCounter = wepCounter;//���� ī���� ���� Ȯ��
	};
	struct RegenHP //ü��
	{
		double regenHP;
	};

	struct EVADE //ȸ�� Ȯ��   // takeDamage()
	{
		int wepEvade=0;//������ ȸ�� Ȯ��
		int minEvade = 8;
		int perEvade = wepEvade + minEvade; // ���� ȸ�� Ȯ��
	};

	struct VAMP //���� ///// attack()
	{
		int wepVamp=0;
		int minVamp = 8;
		int perVamp = wepVamp + minVamp;
	};
	struct CRIT_CHAN //ũ��Ƽ�� ������  ///// attack()
	{
	//2��� �� ����
	
	};
	struct CRIT_PERC //ũ��Ƽ�� Ȯ��  ///// attack()
	{
		int wepCRITPERC = 0; // ������ ũ��Ƽ�� Ȯ��
		int minCRITPERC = 0; // �ּ� ũ��Ƽ�� Ȯ��
		int perCRITPERC = wepCRITPERC + minCRITPERC; // ��ü ũ��Ƽ�� Ȯ��
	};
	struct RETDMG //���� ������  ///// attack()
	{
		int AllDmg;
	};
	
	struct LevelUp //������ ����
	{
		int level=1;
		int maxExp = 200;
		int exp=0;
	};
	
	


}

