#include "LoopMonster.h"
#include "chTime.h"
#include "chSceneManager.h"
#include "chInput.h"
#include "chScene.h"
#include "chImage.h"
#include "chResources.h"
#include "chAnimator.h"
#include "WarriorMini.h"
#include "FightPageOBJ.h"
#include "LoopWarrior.h"

namespace ch
{

	Monsters::Monsters()
	{
	
	
	}
	Monsters::Monsters(int monsIndex, Vector2 pos)
	{
		if (monsIndex == 1) //������
		{
			SetName(L"SlimeMonster");
			SetPos(pos);
			SetScale({ 3.0f, 3.0f });

			if (mImage == nullptr)
			{
				mImage = Resources::Load<Image>(L"Monster", L"..\\Resources\\loophero\\monster\\Slime\\idle\\s_slime_idle_0.bmp");
			}
			mAnimator = new Animator();
			mAnimator->CreateAnimations(L"..\\Resources\\loophero\\monster\\Slime\\idle", L"SlimeIdle");
			mAnimator->CreateAnimations(L"..\\Resources\\loophero\\monster\\Slime\\attack", L"Slimeattack", { 2,2 }, 0.3f);
			mAnimator->CreateAnimations(L"..\\Resources\\loophero\\monster\\Slime\\hurt", L"SlimeHurt", { 2,2 }, 0.3f);
			mAnimator->CreateAnimations(L"..\\Resources\\loophero\\monster\\Slime\\death", L"SlimeDeath", { 2,2 }, 0.3f);

			mAnimator->Play(L"SlimeIdle", true);
			AddComponent(mAnimator);

			//������ �⺻ ü��
			mHP.baseHp = 13;
			mATT.baseStr = 3.3;
			mDEF.baseDef = 0;


			//���� ��������
			mHP.nowHP = mHP.baseHp * WarriorMini::Loop;// ���� HP 
			mATT.nowStr = mATT.baseStr * WarriorMini::Loop;
			mDEF.nowDef = mDEF.baseDef * WarriorMini::Loop;
			mSPD.spd = 0.6;
			MonsterIndex = monsIndex;
		}
		else if (monsIndex == 2) //�Ź�
		{
			SetName(L"SpiderMonster");
			SetPos(pos);
			SetScale({ 3.0f, 3.0f });

			mAnimator = new Animator();
			mAnimator->CreateAnimations(L"..\\Resources\\loophero\\monster\\Spider\\idle", L"SpiderIdle");
			mAnimator->CreateAnimations(L"..\\Resources\\loophero\\monster\\Spider\\attack", L"Spiderattack", { 2,2 }, 0.3f);
			mAnimator->CreateAnimations(L"..\\Resources\\loophero\\monster\\Spider\\hurt", L"SpiderHurt", { 2,2 }, 0.3f);
			mAnimator->CreateAnimations(L"..\\Resources\\loophero\\monster\\Spider\\death", L"SpiderDeath", { 2,2 }, 0.3f);//�Ź� ����

			mAnimator->Play(L"SpiderIdle", true);
			AddComponent(mAnimator);

			//������ �⺻ ü��
			mHP.baseHp = 8;
			mATT.baseStr = 3.1;
			mDEF.baseDef = 0.4;


			//���� ��������
			mHP.nowHP = mHP.baseHp * WarriorMini::Loop;// ���� HP 
			mATT.nowStr = mATT.baseStr * WarriorMini::Loop;
			mDEF.nowDef = mDEF.baseDef * WarriorMini::Loop;
			mSPD.spd = 0.91;
			MonsterIndex = monsIndex;
		}
		else if (monsIndex == 3) //�����̾�
		{
			SetName(L"VampireMonster");
			SetPos(pos);
			SetScale({ 3.0f, 3.0f });

			mAnimator = new Animator();
			mAnimator->CreateAnimations(L"..\\Resources\\loophero\\monster\\Vampire\\Idle", L"VampireIdle");
			mAnimator->CreateAnimations(L"..\\Resources\\loophero\\monster\\Vampire\\attack", L"Vampireattack", { 2,2 }, 0.3f);
			mAnimator->CreateAnimations(L"..\\Resources\\loophero\\monster\\Vampire\\hurt", L"VampireHurt", { 2,2 }, 0.3f);
			mAnimator->CreateAnimations(L"..\\Resources\\loophero\\monster\\Vampire\\death", L"VampireDeath", { 2,2 }, 0.3f); //����

			mAnimator->Play(L"VampireIdle", true);
			AddComponent(mAnimator);

			//������ �⺻ ü��
			mHP.baseHp = 18;
			mATT.baseStr =5.8;
			mDEF.baseDef = 0.5;


			//���� ��������
			mHP.nowHP = mHP.baseHp * WarriorMini::Loop;// ���� HP 
			mATT.nowStr = mATT.baseStr * WarriorMini::Loop;
			mDEF.nowDef = mDEF.baseDef * WarriorMini::Loop;
			mSPD.spd = 0.5;
			MonsterIndex = monsIndex;
		
		}
		else if (monsIndex == 4) //�鰳
		{
			SetName(L"DogMonster");
			SetPos(pos);
			SetScale({ 3.0f, 3.0f });

			mAnimator = new Animator();
			mAnimator->CreateAnimations(L"..\\Resources\\loophero\\monster\\Dog\\idle", L"DogIdle");
			mAnimator->CreateAnimations(L"..\\Resources\\loophero\\monster\\Dog\\attack", L"Dogattack", { 2,2 }, 0.3f);
			mAnimator->CreateAnimations(L"..\\Resources\\loophero\\monster\\Dog\\hurt", L"DogHurt", { 2,2 }, 0.3f);
			mAnimator->CreateAnimations(L"..\\Resources\\loophero\\monster\\Dog\\death", L"DogDeath", { 2,2 }, 0.3f); //����

			mAnimator->Play(L"DogIdle", true);
			AddComponent(mAnimator);

			//������ �⺻ ü��
			mHP.baseHp = 16;
			mATT.baseStr = 3.6;
			mDEF.baseDef = 0.2;


			//���� ��������
			mHP.nowHP = mHP.baseHp * WarriorMini::Loop;// ���� HP 
			mATT.nowStr = mATT.baseStr * WarriorMini::Loop;
			mDEF.nowDef = mDEF.baseDef * WarriorMini::Loop;
			mSPD.spd = 0.75;
			MonsterIndex = monsIndex;
		
		}
		else if (monsIndex == 5) //���̷���
		{
		SetName(L"SkeletonMonster");
		SetPos(pos);
		SetScale({ 3.0f, 3.0f });

		mAnimator = new Animator();
		mAnimator->CreateAnimations(L"..\\Resources\\loophero\\monster\\Skeleton\\idle", L"SkeletonIdle");
		mAnimator->CreateAnimations(L"..\\Resources\\loophero\\monster\\Skeleton\\attack", L"Skeletonattack", { 2,2 }, 0.3f);
		mAnimator->CreateAnimations(L"..\\Resources\\loophero\\monster\\Skeleton\\hurt", L"SkeletonHurt", { 2,2 }, 0.3f);
		mAnimator->CreateAnimations(L"..\\Resources\\loophero\\monster\\Skeleton\\death", L"SkeletonDeath", { 2,2 }, 0.3f); //����

		mAnimator->Play(L"SkeletonIdle", true);
		AddComponent(mAnimator);

		//������ �⺻ ü��
		mHP.baseHp = 12;
		mATT.baseStr = 9;
		mDEF.baseDef = 0.3;


		//���� ��������
		mHP.nowHP = mHP.baseHp * WarriorMini::Loop;// ���� HP 
		mATT.nowStr = mATT.baseStr * WarriorMini::Loop;
		mDEF.nowDef = mDEF.baseDef * WarriorMini::Loop;
		mSPD.spd = 0.35;
		MonsterIndex = monsIndex;
		
		}
		
	}

	Monsters::~Monsters()
	{
	
	
	}

	void Monsters::Tick()
	{
		GameObject::Tick();

		Vector2 pos = GetPos();

		SetPos(pos);

		if (mHP.nowHP > 0) 
		{
			attSpdChek += Time::DeltaTime();
		}

		if (attSpdChek >= (1 / mSPD.spd)) //���ݼӵ�
		{
			mAttack();
			attSpdChek = 0;
		}

	}

	void Monsters::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	void Monsters::mSetTarget()
	{//�÷��̾� ����


	}

	void Monsters::mAttack()
	{
		//����
		if (MonsterIndex == 1) 
		{
			mAnimator->Play(L"Slimeattack", false);
			FightPageOBJ::Testplayer->takeDamage(mATT.nowStr);
		}
		else if (MonsterIndex == 2) 
		{
			mAnimator->Play(L"Spiderattack", false);
			FightPageOBJ::Testplayer->takeDamage(mATT.nowStr);
		}
		else if (MonsterIndex == 3)
		{
			mAnimator->Play(L"Vampireattack", false);
			FightPageOBJ::Testplayer->takeDamage(mATT.nowStr);
		}
		else if (MonsterIndex == 4)
		{
			mAnimator->Play(L"Dogattack", false);
			FightPageOBJ::Testplayer->takeDamage(mATT.nowStr);
		}
		else if (MonsterIndex == 5)
		{
			mAnimator->Play(L"Skeletonattack", false);
			FightPageOBJ::Testplayer->takeDamage(mATT.nowStr);
		}
	}

	void Monsters::mTakeDamage(double damage) //������ ������
	{
		if (MonsterIndex == 1)
		{
			mHP.nowHP -= mCalcDef(damage);//������ ������
			if (mHP.nowHP <= 0)
			{
				mAnimator->Play(L"SlimeDeath", false);//���� �ִϸ��̼�
			}
			else 
			{
				mAnimator->Play(L"SlimeHurt", false);
			}
			
		}
		else if (MonsterIndex == 2) 
		{
			mHP.nowHP -= mCalcDef(damage);//������ ������
			if (mHP.nowHP <= 0)
			{
				mAnimator->Play(L"SpiderDeath", false);//���� �ִϸ��̼�
			}
			else
			{
				mAnimator->Play(L"SpiderHurt", false);
			}
		
		}
		else if (MonsterIndex == 3)
		{
			mHP.nowHP -= mCalcDef(damage);//������ ������
			if (mHP.nowHP <= 0)
			{
				mAnimator->Play(L"VampireDeath", false);//���� �ִϸ��̼�
			}
			else
			{
				mAnimator->Play(L"VampireHurt", false);
			}

		}
		else if (MonsterIndex == 4)
		{
			mHP.nowHP -= mCalcDef(damage);//������ ������
			if (mHP.nowHP <= 0)
			{
				mAnimator->Play(L"DogDeath", false);//���� �ִϸ��̼�
			}
			else
			{
				mAnimator->Play(L"DogHurt", false);
			}

		}
		else if (MonsterIndex == 5)
		{
			mHP.nowHP -= mCalcDef(damage);//������ ������
			if (mHP.nowHP <= 0)
			{
				mAnimator->Play(L"SkeletonDeath", false);//���� �ִϸ��̼�
			}
			else
			{
				mAnimator->Play(L"SkeletonHurt", false);
			}

		}

		
	}



	double Monsters::mCalcDef(double damage) // ���� ���
	{
		double Finaldmg = 0;

		Finaldmg = damage - mDEF.baseDef;

		return Finaldmg;
	}



	void Monsters::mItems()
	{
		//������ ���� �Լ�
	}

	void Monsters::checkHp()
	{

	}


}