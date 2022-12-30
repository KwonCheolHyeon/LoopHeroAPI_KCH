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
			//mAnimator->CreateAnimations(L"..\\Resources\\loophero\\monster\\Spider\\death", L"SlimeDeath", { 2,2 }, 0.3f); 거미 죽음

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
		
		
		}
		else if (monsIndex == 4) 
		{
		
		
		}
		else if (monsIndex == 5) 
		{
		
		
		}
		else if (monsIndex == 6) 
		{
		
		
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

		if (mHP.nowHP >= 0) 
		{
			attSpdChek += Time::DeltaTime();
		}

		if (attSpdChek >= (1 / mSPD.spd)) //공격속도
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
	{//플레이어 선택


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
	}

	void Monsters::mTakeDamage(double damage) //데미지 받을때
	{
		if (MonsterIndex == 1)
		{
			mHP.nowHP -= mCalcDef(damage);//데미지 받을때
			if (mHP.nowHP <= 0)
			{
				mAnimator->Play(L"SlimeDeath", false);//죽음 애니메이션
				

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
				mAnimator->Play(L"SpiderHurt", false);//죽음 애니메이션
			}
			else
			{
				mAnimator->Play(L"SpiderHurt", false);
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
		//아이템 관련 함수
	}

	void Monsters::checkHp()
	{

	}


}