#include "Slime.h"
#include "chTime.h"
#include "chSceneManager.h"
#include "chInput.h"
#include "chScene.h"
#include "chImage.h"
#include "chResources.h"
#include "chAnimator.h"
#include "chCollider.h"
#include "WarriorMini.h"
#include "FightPageOBJ.h"

namespace ch
{
	Slime::Slime()
	{
		SetName(L"Monster");
		SetPos({ 1600 / 2, 300 / 2 });
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
		//mHP.nowHP = mHP.baseHp * LOOP; 현재 HP 
		//mATT.nowStr = mATT.baseStr * LOOP; 
		//mDEF.nowDef = mDEF.baseDef * LOOP;
		mSPD.spd = 0.6;
		

	}

	Slime::Slime(Vector2 pos)
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
		mHP.nowHP = mHP.baseHp * WarriorMini::Loop; 
		mATT.nowStr = mATT.baseStr * WarriorMini::Loop;
		mDEF.nowDef = mDEF.baseDef * WarriorMini::Loop;
		mSPD.spd = 0.6;

	}

	Slime::~Slime()
	{

	}

	void Slime::Tick()
	{
		GameObject::Tick();

		Vector2 pos = GetPos();

		SetPos(pos);

		attSpdChek += Time::DayTime();

		if (attSpdChek >= ( 1 / mSPD.spd)) //공격속도
		{
			mAttack();
			attSpdChek = 0;
		}


		if (KEY_DOWN(eKeyCode::Q))
		{
			mAnimator->Play(L"SlimeIdle", true);

		}
		if (KEY_DOWN(eKeyCode::W))
		{
			mAnimator->Play(L"Slimeattack", true);
		}
		if (KEY_DOWN(eKeyCode::E))
		{
			mAnimator->Play(L"SlimeHurt", true);
		}
		if (KEY_DOWN(eKeyCode::R))
		{
			mAnimator->Play(L"SlimeDeath", true);
		}

	}

	void Slime::Render(HDC hdc)
	{
		

		GameObject::Render(hdc);
	}

	void Slime::mSetTarget()
	{//플레이어 선택
		
		
	}

	void Slime::mAttack()
	{
		//공격
		FightPageOBJ::Testplayer->takeDamage(mATT.nowStr);
		attSpdChek = 0;
	}

	void Slime::takeDamage(double damage) //데미지 받을때
	{
		
		mHP.nowHP -= calcDEF(damage);//데미지 받을때
		if (mHP.nowHP <= 0) 
		{
			mAnimator->Play(L"SlimeDeath", false);//죽음 애니메이션
			
		}
		mAnimator->Play(L"SlimeHurt", false);
	}



	double Slime::calcDEF(double damage) // 방어력 계산
	{
		double Finaldmg = 0;

		Finaldmg = damage - mDEF.baseDef;

		return Finaldmg;
	}



	void Slime::ITEMs()
	{
		//아이템 관련 함수
	}

}
