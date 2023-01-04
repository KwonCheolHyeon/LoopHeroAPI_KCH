#include "chLeach.h"
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

namespace ch
{
	Leach::Leach()
	{
	}

	Leach::Leach(int monsterIndex,Vector2 position)
	{
		SetName(L"SlimeMonster");
		SetPos(position);
		SetScale({ 3.0f, 3.0f });

		if (mImage == nullptr)
		{
			mImage = Resources::Load<Image>(L"Monster", L"..\\Resources\\loophero\\monster\\Slime\\idle\\s_slime_idle_0.bmp");
		}
		mAnimator = new Animator();
		mAnimator->CreateAnimations(L"..\\Resources\\loophero\\Boss\\leach\\idle", L"leachIdle");
		mAnimator->CreateAnimations(L"..\\Resources\\loophero\\Boss\\leach\\attack", L"leachattack", { 0,0 }, 0.3f);
		mAnimator->CreateAnimations(L"..\\Resources\\loophero\\Boss\\leach\\hurt", L"leachHurt", { 0,0}, 0.3f);
		mAnimator->CreateAnimations(L"..\\Resources\\loophero\\Boss\\leach\\death", L"leachDeath", { 0,0 }, 0.3f);
		mAnimator->CreateAnimations(L"..\\Resources\\loophero\\Boss\\leach\\firstStart", L"leachFirst", { 0,0 }, 0.3f);///6초 대기 시간 추가 해주기

		mAnimator->Play(L"leachFirst", false);
		AddComponent(mAnimator);

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

	Leach::~Leach()
	{
	}

	void Leach::Tick() // 6초뒤 작동
	{
		GameObject::Tick();

		Vector2 pos = GetPos();

		SetPos(pos);


		if (mHP.nowHP > 0)
		{
			//attSpdChek += Time::DeltaTime();
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

	void Leach::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	void Leach::mAttack()
	{
		mAnimator->Play(L"leachattack", false);
		FightPageOBJ::Testplayer->takeDamage(mATT.nowStr);
	}

	void Leach::mTakeDamage(double damage)
	{
		mHP.nowHP -= mCalcDef(damage);//데미지 받을때
		if (mHP.nowHP <= 0)
		{
			mAnimator->Play(L"leachDeath", false);//죽음 애니메이션
			death = true;
		}
		else
		{
			mAnimator->Play(L"leachHurt", false);
		}
	}

	double Leach::mCalcDef(double damage)
	{
		double Finaldmg = 0;

		Finaldmg = damage - mDEF.baseDef;

		return Finaldmg;
	}

	void Leach::mItems()
	{
		int rank = 3; // 0~3;
		int item = rand() % 4; // 0~3;
		int itemType = rand() % 4+1; // 0~4

		if (fullItemCheck())
		{
			ch::object::Instantiate<ItemBG>(rank, item, itemType, (eColliderLayer::Card));

		}
	}

	void Leach::checkHp()
	{

	}

	bool Leach::fullItemCheck()
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

}