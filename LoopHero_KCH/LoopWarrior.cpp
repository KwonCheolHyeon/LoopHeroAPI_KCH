#include "LoopWarrior.h"
#include "chTime.h"
#include "chSceneManager.h"
#include "chInput.h"
#include "chScene.h"
#include "chImage.h"
#include "chResources.h"
#include "chAnimator.h"
#include "chCamera.h"
#include "chCollider.h"
#include "Maths.h"
#include "FightPageOBJ.h"
#include "LoopMonster.h"
#include "chObject.h"
#include "chItemBG.h"


namespace ch 
{
	
	LoopWarrior::LoopWarrior()
	{
		SetName(L"Warrior");
		SetPos({ 200.0f, 300.0f });
		SetScale({ 6.0f, 6.0f });
		pHp.maxHp = pHp.wepHp + pHp.minHp;

		if (mImage == nullptr)
		{
			mImage = Resources::Load<Image>(L"Warrior", L"..\\Resources\\loophero\\character\\warrior\\idle\\idle_01.bmp");
		}
	
		mAnimator = new Animator();
		mAnimator->CreateAnimations(L"..\\Resources\\loophero\\character\\warrior\\idle", L"WarriorIdle");//전투 기본모션
		mAnimator->CreateAnimations(L"..\\Resources\\loophero\\character\\warrior\\attack", L"Warriorattack",{2,2}, 0.3f);//전투 모션
		mAnimator->CreateAnimations(L"..\\Resources\\loophero\\character\\warrior\\hurt", L"WarrioraHurt", { 2,2 }, 0.3f); // 데미지 받을때 모션
		mAnimator->CreateAnimations(L"..\\Resources\\loophero\\character\\warrior\\death", L"WarrioraDeath", { 2,2 }, 0.3f); // 죽음 모션
		mAnimator->Play(L"WarriorIdle", true);
		

		AddComponent(mAnimator);
		srand(time(NULL));
	}

	LoopWarrior::LoopWarrior(Vector2 pos)
	{
		SetName(L"Warrior");
		SetPos(pos);
		SetScale({ 2.5f, 2.5f });
		pHp.maxHp = pHp.wepHp + pHp.minHp;

		if (mImage == nullptr)
		{
			mImage = Resources::Load<Image>(L"Warrior", L"..\\Resources\\loophero\\character\\warrior\\idle\\idle_01.bmp");
		}

		mAnimator = new Animator();
		mAnimator->CreateAnimations(L"..\\Resources\\loophero\\character\\warrior\\idle", L"WarriorIdle");//전투 기본모션
		mAnimator->CreateAnimations(L"..\\Resources\\loophero\\character\\warrior\\attack", L"Warriorattack", { 0,0 }, 0.3f);//전투 모션
		mAnimator->CreateAnimations(L"..\\Resources\\loophero\\character\\warrior\\hurt", L"WarrioraHurt", {0,0 }, 0.2f); // 데미지 받을때 모션
		mAnimator->CreateAnimations(L"..\\Resources\\loophero\\character\\warrior\\death", L"WarrioraDeath", { 0,0 }, 0.2f); // 죽음 모션
		mAnimator->Play(L"WarriorIdle", true);


		AddComponent(mAnimator);
		srand(time(NULL));

		pSpd.AttSpeed = 1;
		pHp.maxHp = pHp.minHp + pHp.wepHp;
		pHp.nowHp = pHp.maxHp;
		
		pDef.maxDef = 3;
		pDef.minDef = 1;

		monsterCount = 0;
		FightDone = false;
	}

	bool LoopWarrior::FightDone;

	LoopWarrior::~LoopWarrior()
	{

	}

	void LoopWarrior::Tick()
	{

		playerRegenTime += (Time::DeltaTime()); // 1초당 리젠 시간;
		playerAttSpd += Time::DeltaTime();

		GameObject::Tick();
		Vector2 pos = GetPos();
		Vector2 scale = GetScale();

		SetPos(pos);
		
		if(playerRegenTime >= 1.0f)//초당 회복
		{
			pRegenHP();
			mAnimator->Play(L"WarriorIdle", false);
			playerRegenTime = 0;
		}
		

		if (playerAttSpd >= (1 / pSpd.AttSpeed)) //공격속도
		{
			if (FightPageOBJ::enemys[monsterCount]->GetHp() >= 0)
			{
				mAnimator->Play(L"Warriorattack", false);
				Attack();
				
				playerAttSpd = 0;

				EndFightCheck();
			}
		}

		
	
	}

	void LoopWarrior::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	void LoopWarrior::EndFightCheck() //전투 종료 확인
	{
		if (monsterCount == FightPageOBJ::fightPageMonsterCount)//전투 종료
		{
			FightDone = true;
		}
	}

	void LoopWarrior::Attack() // 공격
	{

		if (pCritical()) //크리티컬 
		{
			FightPageOBJ::enemys[monsterCount]->mTakeDamage(pAttSelect() * 2);

			if (FightPageOBJ::enemys[monsterCount]->GetHp() <= 0)//공격하고나서 해당 적 체력이 바닥이면 다음 친구 공격
			{
				monsterCount++;
			}
		}
		else
		{
			FightPageOBJ::enemys[monsterCount]->mTakeDamage(pAttSelect());

			if (FightPageOBJ::enemys[monsterCount]->GetHp() <= 0)
			{
				monsterCount++;
			}
		}
	}

	void LoopWarrior::takeDamage(double damage) // 데미지 받을때
	{
		if (pAvoid()) //회피 성공
		{
			//회피했다고 글 
		}
		else
		{
			mAnimator->Play(L"WarrioraHurt", false);
			pHp.nowHp -= calcDEF(damage);//데미지 받을때
			if ( pCounterAtt() ) //반격확률 계산하고 성공시 공격
			{
				Attack();
				playerAttSpd = 0;
			}
		}
		
	}

	double LoopWarrior::calcDEF(double damage)//방어력 계산
	{
		double Finaldmg = 0;

		Finaldmg = 0.5 * damage * (20.3125 / (18.75 + pDefSelect() - (0.5 * damage)) - (1 / 12));//방어력 계산식

		return Finaldmg;
	}



	void LoopWarrior::pRegenHP() // 체력 재생   Tick();
	{
		if (plive == true) {
			pHp.nowHp += pRegen.regenHP;
		}
	}

	void LoopWarrior::checkStat()//체력 관련
	{
		//hp 관련
		pHp.maxHp = pHp.wepHp + pHp.minHp;

		if (pHp.nowHp > pHp.maxHp)
		{
			pHp.nowHp = pHp.maxHp;
		}

		if (pHp.nowHp < 0) 	//게임오버
		{
			plive = false;//플레이어 죽음
			mAnimator->Play(L"WarrioraDeath", false);
		}
		//hp관련 끝



	}

	void LoopWarrior::randStat()//아이템에 따른 스텟 정해줌 Tick();
	{
		pAtt.nowAtt = rand() % (pAtt.maxAtt- pAtt.minAtt + 1) + pAtt.minAtt;

		pDef.nowDef = rand() % (pDef.maxDef- pDef.minDef +1) + pDef.minDef;

		pEvade.perEvade = pEvade.minEvade + pEvade.wepEvade; //회피율

		pCriticalPer.perCRITPERC = pCriticalPer.wepCRITPERC;

		pCounterAtk.perCounter = pCounterAtk.wepCounter;
	}

	void LoopWarrior::ppLevelUp(int mEXP)//레벨업 관련
	{
		pExp.exp += mEXP; //몬스터로부터 경험치를 받는다.
		if (pExp.maxExp <= pExp.exp) 
		{
			pExp.level++;
			pExp.exp = 0;
		}

	}



	bool LoopWarrior::pAvoid()//피하는 확률
	{
		int finalEvade = rand() % 100+1;

		if (pEvade.perEvade >= finalEvade) 
		{
			return true;
		}
		else 
		{
			return false;
		}
	}

	bool LoopWarrior::pCounterAtt() // 반격 확률
	{
		int finalCounter = rand() % 100 + 1;
		
		if(pCounterAtk.perCounter >= finalCounter)
		{
			return true;
		}
		else 
		{
			return false;
		}
	}

	bool LoopWarrior::pCritical()//크리티컬 확률
	{
		int finalCritical = rand() % 100 + 1;
		if (pCriticalPer.perCRITPERC >= finalCritical) 
		{
			return true;
		}
		else 
		{
			return false;
		}
	}

	double LoopWarrior::pDefSelect() 
	{
		float nowDef =rand() % (pDef.maxDef - pDef.minDef + 1) + pDef.minDef;

		return nowDef;
	}

	int LoopWarrior::pAttSelect()
	{
		int nowAtt = rand() % (pAtt.maxAtt - pAtt.minAtt + 1) + pAtt.minAtt;

		return nowAtt;
	}

	

}