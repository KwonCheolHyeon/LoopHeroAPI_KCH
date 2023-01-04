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
namespace ch
{

	Monsters::Monsters()
	{
	
	
	}
	Monsters::Monsters(int monsIndex, Vector2 pos)
	{
		if (monsIndex == 1) //슬라임
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

			//슬라임 기본 체력
			mHP.baseHp = 13;
			mATT.baseStr = 3.3;
			mDEF.baseDef = 0;


			//몬스터 리스폰시
			mHP.nowHP = mHP.baseHp * WarriorMini::Loop;// 현재 HP 
			mATT.nowStr = mATT.baseStr * WarriorMini::Loop;
			mDEF.nowDef = mDEF.baseDef * WarriorMini::Loop;
			mSPD.spd = 0.6;
			MonsterIndex = monsIndex;
		}
		else if (monsIndex == 2) //거미
		{
			SetName(L"SpiderMonster");
			SetPos(pos);
			SetScale({ 3.0f, 3.0f });

			mAnimator = new Animator();
			mAnimator->CreateAnimations(L"..\\Resources\\loophero\\monster\\Spider\\idle", L"SpiderIdle");
			mAnimator->CreateAnimations(L"..\\Resources\\loophero\\monster\\Spider\\attack", L"Spiderattack", { 2,2 }, 0.3f);
			mAnimator->CreateAnimations(L"..\\Resources\\loophero\\monster\\Spider\\hurt", L"SpiderHurt", { 2,2 }, 0.3f);
			mAnimator->CreateAnimations(L"..\\Resources\\loophero\\monster\\Spider\\death", L"SpiderDeath", { 2,2 }, 0.3f);//거미 죽음

			mAnimator->Play(L"SpiderIdle", true);
			AddComponent(mAnimator);

			//슬라임 기본 체력
			mHP.baseHp = 8;
			mATT.baseStr = 3.1;
			mDEF.baseDef = 0.4;


			//몬스터 리스폰시
			mHP.nowHP = mHP.baseHp * WarriorMini::Loop;// 현재 HP 
			mATT.nowStr = mATT.baseStr * WarriorMini::Loop;
			mDEF.nowDef = mDEF.baseDef * WarriorMini::Loop;
			mSPD.spd = 0.91;
			MonsterIndex = monsIndex;
		}
		else if (monsIndex == 3) //뱀파이어
		{
			SetName(L"VampireMonster");
			SetPos(pos);
			SetScale({ 3.0f, 3.0f });

			mAnimator = new Animator();
			mAnimator->CreateAnimations(L"..\\Resources\\loophero\\monster\\Vampire\\Idle", L"VampireIdle");
			mAnimator->CreateAnimations(L"..\\Resources\\loophero\\monster\\Vampire\\attack", L"Vampireattack", { 2,2 }, 0.3f);
			mAnimator->CreateAnimations(L"..\\Resources\\loophero\\monster\\Vampire\\hurt", L"VampireHurt", { 2,2 }, 0.3f);
			mAnimator->CreateAnimations(L"..\\Resources\\loophero\\monster\\Vampire\\death", L"VampireDeath", { 2,2 }, 0.3f); //죽음

			mAnimator->Play(L"VampireIdle", true);
			AddComponent(mAnimator);

			//슬라임 기본 체력
			mHP.baseHp = 18;
			mATT.baseStr =5.8;
			mDEF.baseDef = 0.5;


			//몬스터 리스폰시
			mHP.nowHP = mHP.baseHp * WarriorMini::Loop;// 현재 HP 
			mATT.nowStr = mATT.baseStr * WarriorMini::Loop;
			mDEF.nowDef = mDEF.baseDef * WarriorMini::Loop;
			mSPD.spd = 0.5;
			MonsterIndex = monsIndex;
		
		}
		else if (monsIndex == 4) //들개
		{
			SetName(L"DogMonster");
			SetPos(pos);
			SetScale({ 3.0f, 3.0f });

			mAnimator = new Animator();
			mAnimator->CreateAnimations(L"..\\Resources\\loophero\\monster\\Dog\\idle", L"DogIdle");
			mAnimator->CreateAnimations(L"..\\Resources\\loophero\\monster\\Dog\\attack", L"Dogattack", { 2,2 }, 0.3f);
			mAnimator->CreateAnimations(L"..\\Resources\\loophero\\monster\\Dog\\hurt", L"DogHurt", { 2,2 }, 0.3f);
			mAnimator->CreateAnimations(L"..\\Resources\\loophero\\monster\\Dog\\death", L"DogDeath", { 2,2 }, 0.3f); //죽음

			mAnimator->Play(L"DogIdle", true);
			AddComponent(mAnimator);

			//슬라임 기본 체력
			mHP.baseHp = 16;
			mATT.baseStr = 3.6;
			mDEF.baseDef = 0.2;


			//몬스터 리스폰시
			mHP.nowHP = mHP.baseHp * WarriorMini::Loop;// 현재 HP 
			mATT.nowStr = mATT.baseStr * WarriorMini::Loop;
			mDEF.nowDef = mDEF.baseDef * WarriorMini::Loop;
			mSPD.spd = 0.75;
			MonsterIndex = monsIndex;
		
		}
		else if (monsIndex == 5) //스켈레톤
		{
		SetName(L"SkeletonMonster");
		SetPos(pos);
		SetScale({ 3.0f, 3.0f });

		mAnimator = new Animator();
		mAnimator->CreateAnimations(L"..\\Resources\\loophero\\monster\\Skeleton\\idle", L"SkeletonIdle");
		mAnimator->CreateAnimations(L"..\\Resources\\loophero\\monster\\Skeleton\\attack", L"Skeletonattack", { 2,2 }, 0.3f);
		mAnimator->CreateAnimations(L"..\\Resources\\loophero\\monster\\Skeleton\\hurt", L"SkeletonHurt", { 2,2 }, 0.3f);
		mAnimator->CreateAnimations(L"..\\Resources\\loophero\\monster\\Skeleton\\death", L"SkeletonDeath", { 2,2 }, 0.3f); //죽음

		mAnimator->Play(L"SkeletonIdle", true);
		AddComponent(mAnimator);

		//슬라임 기본 체력
		mHP.baseHp = 12;
		mATT.baseStr = 9;
		mDEF.baseDef = 0.3;


		//몬스터 리스폰시
		mHP.nowHP = mHP.baseHp * WarriorMini::Loop;// 현재 HP 
		mATT.nowStr = mATT.baseStr * WarriorMini::Loop;
		mDEF.nowDef = mDEF.baseDef * WarriorMini::Loop;
		mSPD.spd = 0.35;
		MonsterIndex = monsIndex;
		
		}
		else if (monsIndex == 6) //리치
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
		mAnimator->CreateAnimations(L"..\\Resources\\loophero\\Boss\\leach\\firstStart", L"leachFirst", { 0,0 }, 0.3f);///6초 대기 시간 추가 해주기

		
		AddComponent(mAnimator);
		MonsterIndex = monsIndex;
		//리치 스텟
		mHP.baseHp = 110;
		mATT.baseStr = 16;
		mDEF.baseDef = 1.3;


		//리치 
		mHP.nowHP = mHP.baseHp * WarriorMini::Loop;// 현재 HP 
		mATT.nowStr = mATT.baseStr * WarriorMini::Loop;
		mDEF.nowDef = mDEF.baseDef * WarriorMini::Loop;
		mSPD.spd = 0.36;
		}
		lichTimeCheck = true;
		lichTime = 0;
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

		if (MonsterIndex == 6) //리치
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
					mItems();
				}

				if (attSpdChek >= (1 / mSPD.spd)) //공격속도
				{
					mAttack();
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

			if (attSpdChek >= (1 / mSPD.spd)) //공격속도
			{
				mAttack();
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
		//공격
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

	void Monsters::mTakeDamage(double damage) //데미지 받을때
	{
		if (MonsterIndex == 1)
		{
			mHP.nowHP -= mCalcDef(damage);//데미지 받을때
			if (mHP.nowHP <= 0)
			{
				mAnimator->Play(L"SlimeDeath", false);//죽음 애니메이션
				death = true;
			}
			else 
			{
				mAnimator->Play(L"SlimeHurt", false);
			}
			
		}
		else if (MonsterIndex == 2) 
		{
			mHP.nowHP -= mCalcDef(damage);//데미지 받을때
			if (mHP.nowHP <= 0)
			{
				mAnimator->Play(L"SpiderDeath", false);//죽음 애니메이션
				death = true;
			}
			else
			{
				mAnimator->Play(L"SpiderHurt", false);
			}
		
		}
		else if (MonsterIndex == 3)
		{
			mHP.nowHP -= mCalcDef(damage);//데미지 받을때
			if (mHP.nowHP <= 0)
			{
				mAnimator->Play(L"VampireDeath", false);//죽음 애니메이션
				death = true;
			}
			else
			{
				mAnimator->Play(L"VampireHurt", false);
			}

		}
		else if (MonsterIndex == 4)
		{
			mHP.nowHP -= mCalcDef(damage);//데미지 받을때
			if (mHP.nowHP <= 0)
			{
				mAnimator->Play(L"DogDeath", false);//죽음 애니메이션
				death = true;
			}
			else
			{
				mAnimator->Play(L"DogHurt", false);
			}

		}
		else if (MonsterIndex == 5)
		{
			mHP.nowHP -= mCalcDef(damage);//데미지 받을때
			if (mHP.nowHP <= 0)
			{
				mAnimator->Play(L"SkeletonDeath", false);//죽음 애니메이션
				death = true;
			}
			else
			{
				mAnimator->Play(L"SkeletonHurt", false);
			}
		}
		else if (MonsterIndex == 6)
		{
			mHP.nowHP -= mCalcDef(damage);//데미지 받을때
			if (mHP.nowHP <= 0 )
			{
				mAnimator->Play(L"leachDeath", false);//죽음 애니메이션
				death = true;
			}
			else
			{
				mAnimator->Play(L"leachHurt", false);
			}
		}

	}



	double Monsters::mCalcDef(double damage) // 방어력 계산
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
		else if (MonsterIndex == 2) // 거미
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
		else if (MonsterIndex == 3) // 뱀파이어
		{
			rank = rand() % 3 + 1;
			item = rand() % 4;
			itemType = rand() % 4 + 1;
		}
		else if (MonsterIndex == 4) // 들개
		{
			rank = rand() % 3 + 1;
			item = rand() % 4;
			itemType = rand() % 4 + 1;
		}
		else if (MonsterIndex == 5) // 스켈레톤
		{
			rank = rand() % 3 + 1;
			item = rand() % 4;
			itemType = rand() % 4 + 1;
		}
		else if (MonsterIndex == 5) // 스켈레톤
		{
			rank = 3; // 0~3;
			item = rand() % 4; // 0~3;
			itemType = rand() % 4 + 1; // 0~4
		}

		if (fullItemCheck())
		{
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