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
#include "chObject.h"
#include "chItemBG.h"
#include "chLeach.h"
#include "LoopWarrior.h"
#include "chSound.h"
#include "chSoundManager.h"


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
			mHP.baseHp = 18;
			mATT.baseStr = 5;
			mDEF.baseDef = 0;


			//���� ��������
			mHP.nowHP = mHP.baseHp * WarriorMini::Loop;// ���� HP 
			mATT.nowStr = mATT.baseStr * WarriorMini::Loop;
			mDEF.nowDef = mDEF.baseDef * WarriorMini::Loop;
			mSPD.spd = 0.6;
			MonsterIndex = monsIndex;
			monsterAttack_sound = Resources::Load<Sound>(L"monsterAtk", L"..\\Resources\\sound\\monster\\snd_slime_attack3.wav");
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
			mHP.baseHp = 13;
			mATT.baseStr = 5;
			mDEF.baseDef = 0.4;


			//���� ��������
			mHP.nowHP = mHP.baseHp * WarriorMini::Loop;// ���� HP 
			mATT.nowStr = mATT.baseStr * WarriorMini::Loop;
			mDEF.nowDef = mDEF.baseDef * WarriorMini::Loop;
			mSPD.spd = 0.91;
			MonsterIndex = monsIndex;
			monsterAttack_sound = Resources::Load<Sound>(L"monsterAtk", L"..\\Resources\\sound\\monster\\snd_spider_attack.wav");
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
			mHP.baseHp = 24;
			mATT.baseStr =10;
			mDEF.baseDef = 0.5;


			//���� ��������
			mHP.nowHP = mHP.baseHp * WarriorMini::Loop;// ���� HP 
			mATT.nowStr = mATT.baseStr * WarriorMini::Loop;
			mDEF.nowDef = mDEF.baseDef * WarriorMini::Loop;
			mSPD.spd = 0.5;
			MonsterIndex = monsIndex;
			monsterAttack_sound = Resources::Load<Sound>(L"monsterAtk", L"..\\Resources\\sound\\monster\\snd_vampire_attack.wav");
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
			mHP.baseHp = 21;
			mATT.baseStr =6;
			mDEF.baseDef = 0.2;


			//���� ��������
			mHP.nowHP = mHP.baseHp * WarriorMini::Loop;// ���� HP 
			mATT.nowStr = mATT.baseStr * WarriorMini::Loop;
			mDEF.nowDef = mDEF.baseDef * WarriorMini::Loop;
			mSPD.spd = 0.75;
			MonsterIndex = monsIndex;
			monsterAttack_sound = Resources::Load<Sound>(L"monsterAtk", L"..\\Resources\\sound\\monster\\snd_wolf_attack.wav");
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

		//���� �⺻ ü��
		mHP.baseHp = 25;
		mATT.baseStr = 9;
		mDEF.baseDef = 0.3;


		//���� ��������
		mHP.nowHP = mHP.baseHp * WarriorMini::Loop;// ���� HP 
		mATT.nowStr = mATT.baseStr * WarriorMini::Loop;
		mDEF.nowDef = mDEF.baseDef * WarriorMini::Loop;
		mSPD.spd = 0.35;
		MonsterIndex = monsIndex;
		monsterAttack_sound = Resources::Load<Sound>(L"monsterAtk", L"..\\Resources\\sound\\monster\\snd_skeleton_damaged_attack.wav");
		}
		else if (monsIndex == 6) //��ġ
		{
		SetName(L"LichMonster");
		SetPos(pos);
		SetScale({ 3.0f, 3.0f });

		if (mImage == nullptr)
		{
			mImage = Resources::Load<Image>(L"Monster", L"..\\Resources\\loophero\\monster\\Slime\\idle\\s_slime_idle_0.bmp");
		}
		mAnimator = new Animator();
		mAnimator->CreateAnimations(L"..\\Resources\\loophero\\Boss\\leach\\idle", L"leachIdle");
		mAnimator->CreateAnimations(L"..\\Resources\\loophero\\Boss\\leach\\attack", L"leachattack", { 0,0 }, 0.1f);
		mAnimator->CreateAnimations(L"..\\Resources\\loophero\\Boss\\leach\\hurt", L"leachHurt", { 0,0 }, 0.1f);
		mAnimator->CreateAnimations(L"..\\Resources\\loophero\\Boss\\leach\\death", L"leachDeath", { 0,0 }, 0.2f);
		mAnimator->CreateAnimations(L"..\\Resources\\loophero\\Boss\\leach\\firstStart", L"leachFirst", { 0,0 }, 0.3f);///6�� ��� �ð� �߰� ���ֱ�

		
		AddComponent(mAnimator);
		MonsterIndex = monsIndex;
		//��ġ ����
		mHP.baseHp = 125;
		mATT.baseStr = 20;
		mDEF.baseDef = 1.3;


		//��ġ 
		mHP.nowHP = mHP.baseHp * WarriorMini::Loop;// ���� HP 
		mATT.nowStr = mATT.baseStr * WarriorMini::Loop;
		mDEF.nowDef = mDEF.baseDef * WarriorMini::Loop;
		mSPD.spd = 0.5;

		lichAttack_sound = Resources::Load<Sound>(L"lichAtk", L"..\\Resources\\sound\\lich\\snd_LICH_attack.wav");
		fightLich_Sound = Resources::Load<Sound>(L"fightLichSound", L"..\\Resources\\sound\\lich\\snd_boss_lich.wav");
		deathLich_Sound = Resources::Load<Sound>(L"deathLich", L"..\\Resources\\sound\\lich\\snd_win_lich.wav");

		fightLich_Sound->Play(true);
		}
		lichTimeCheck = true;
		lichTime = 0;
		itemDrop_sound = Resources::Load<Sound>(L"itemDrop_sound", L"..\\Resources\\sound\\effect\\snd_item_drop1.wav");
		srand(time(NULL));
		death = false;


	}

	Monsters::~Monsters()
	{
	
	
	}

	void Monsters::Tick()
	{
		GameObject::Tick();

		Vector2 pos = GetPos();

		SetPos(pos);

		if (MonsterIndex == 6) //��ġ
		{
			lichTime += Time::DeltaTime();
			
			if (lichTimeCheck == true) 
			{
				FightPageOBJ::Testplayer->gameSpeed = 0;
				lichTimeCheck = false;

				mAnimator->Play(L"leachFirst", false);
			}
			if(lichTime >= 6.0f )
			{
				FightPageOBJ::Testplayer->gameSpeed = 1;
				if (mHP.nowHP > 0)
				{
					attSpdChek += Time::DeltaTime();
				}

				if (death == true)
				{
					death = false;
					fightLich_Sound->Stop(true);
					deathLich_Sound->Play(true);
					mItems();
				}

				if (attSpdChek >= (1 / mSPD.spd)) //���ݼӵ�
				{
					mAttack();
					lichAttack_sound->Play(false);
					attSpdChek = 0;
				}
			
			}


		}
		else 
		{
		
			if (mHP.nowHP > 0)
			{
				attSpdChek += Time::DeltaTime();
			}

			if (death == true)
			{
				death = false;
				mItems();
			}

			if (attSpdChek >= (1 / mSPD.spd)) //���ݼӵ�
			{
				mAttack();
				monsterAttack_sound->Play(false);
				attSpdChek = 0;
			}
		
		
		}
		

		


		

	}

	void Monsters::Render(HDC hdc)
	{
		GameObject::Render(hdc);
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
		else if (MonsterIndex == 6)
		{
			mAnimator->Play(L"leachattack", false);
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
				death = true;
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
				death = true;
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
				death = true;
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
				death = true;
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
				death = true;
			}
			else
			{
				mAnimator->Play(L"SkeletonHurt", false);
			}
		}
		else if (MonsterIndex == 6)
		{
			mHP.nowHP -= mCalcDef(damage);//������ ������
			if (mHP.nowHP <= 0 )
			{
				mAnimator->Play(L"leachDeath", false);//���� �ִϸ��̼�
				death = true;
			}
			else
			{
				mAnimator->Play(L"leachHurt", false);
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
		int rank = rand() % 4; // 0~3;
		int item = rand() % 4; // 0~3;
		int itemType = rand() % 5; // 0~4

		if (MonsterIndex == 1)
		{
			rank = 0;
			item = rand() % 4;
			itemType = 0;
		}
		else if (MonsterIndex == 2) // �Ź�
		{
			int rank = rand() % 4;
			if (rank == 0) 
			{
				item = rand() % 4;
				itemType = 0;
			}
			else
			{
				item = rand() % 4; // 0~3;
				itemType = rand() % 4 + 1; // 0~4
			}
		}
		else if (MonsterIndex == 3) // �����̾�
		{
			rank = rand() % 3 + 1;
			item = rand() % 4;
			itemType = rand() % 4 + 1;
		}
		else if (MonsterIndex == 4) // �鰳
		{
			rank = rand() % 3 + 1;
			item = rand() % 4;
			itemType = rand() % 4 + 1;
		}
		else if (MonsterIndex == 5) // ���̷���
		{
			rank = rand() % 3 + 1;
			item = rand() % 4;
			itemType = rand() % 4 + 1;
		}
		else if (MonsterIndex == 5) // ���̷���
		{
			rank = 3; // 0~3;
			item = rand() % 4; // 0~3;
			itemType = rand() % 4 + 1; // 0~4
		}

		if (fullItemCheck())
		{
			itemDrop_sound->Play(false);
			ch::object::Instantiate<ItemBG>(rank, item, itemType, (eColliderLayer::Card));
		}
	}

	bool Monsters::fullItemCheck()
	{
		int count = 0;

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (ItemBG::bagChecks[i][j] != nullptr)
				{
					count++;
				}
			}
		}

		if (count >= 12)
		{
			return false;
		}
		else if (count < 12)
		{
			return true;
		}
	}


	void Monsters::checkHp()
	{

	}


}