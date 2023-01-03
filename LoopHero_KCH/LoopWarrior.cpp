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
		mAnimator->CreateAnimations(L"..\\Resources\\loophero\\character\\warrior\\idle", L"WarriorIdle");//���� �⺻���
		mAnimator->CreateAnimations(L"..\\Resources\\loophero\\character\\warrior\\attack", L"Warriorattack",{2,2}, 0.3f);//���� ���
		mAnimator->CreateAnimations(L"..\\Resources\\loophero\\character\\warrior\\hurt", L"WarrioraHurt", { 2,2 }, 0.3f); // ������ ������ ���
		mAnimator->CreateAnimations(L"..\\Resources\\loophero\\character\\warrior\\death", L"WarrioraDeath", { 2,2 }, 0.3f); // ���� ���
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
		mAnimator->CreateAnimations(L"..\\Resources\\loophero\\character\\warrior\\idle", L"WarriorIdle");//���� �⺻���
		mAnimator->CreateAnimations(L"..\\Resources\\loophero\\character\\warrior\\attack", L"Warriorattack", { 0,0 }, 0.3f);//���� ���
		mAnimator->CreateAnimations(L"..\\Resources\\loophero\\character\\warrior\\hurt", L"WarrioraHurt", {0,0 }, 0.2f); // ������ ������ ���
		mAnimator->CreateAnimations(L"..\\Resources\\loophero\\character\\warrior\\death", L"WarrioraDeath", { 0,0 }, 0.2f); // ���� ���
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

		playerRegenTime += (Time::DeltaTime()); // 1�ʴ� ���� �ð�;
		playerAttSpd += Time::DeltaTime();

		GameObject::Tick();
		Vector2 pos = GetPos();
		Vector2 scale = GetScale();

		SetPos(pos);
		
		if(playerRegenTime >= 1.0f)//�ʴ� ȸ��
		{
			pRegenHP();
			mAnimator->Play(L"WarriorIdle", false);
			playerRegenTime = 0;
		}
		

		if (playerAttSpd >= (1 / pSpd.AttSpeed)) //���ݼӵ�
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

	void LoopWarrior::EndFightCheck() //���� ���� Ȯ��
	{
		if (monsterCount == FightPageOBJ::fightPageMonsterCount)//���� ����
		{
			FightDone = true;
		}
	}

	void LoopWarrior::Attack() // ����
	{

		if (pCritical()) //ũ��Ƽ�� 
		{
			FightPageOBJ::enemys[monsterCount]->mTakeDamage(pAttSelect() * 2);

			if (FightPageOBJ::enemys[monsterCount]->GetHp() <= 0)//�����ϰ��� �ش� �� ü���� �ٴ��̸� ���� ģ�� ����
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

	void LoopWarrior::takeDamage(double damage) // ������ ������
	{
		if (pAvoid()) //ȸ�� ����
		{
			//ȸ���ߴٰ� �� 
		}
		else
		{
			mAnimator->Play(L"WarrioraHurt", false);
			pHp.nowHp -= calcDEF(damage);//������ ������
			if ( pCounterAtt() ) //�ݰ�Ȯ�� ����ϰ� ������ ����
			{
				Attack();
				playerAttSpd = 0;
			}
		}
		
	}

	double LoopWarrior::calcDEF(double damage)//���� ���
	{
		double Finaldmg = 0;

		Finaldmg = 0.5 * damage * (20.3125 / (18.75 + pDefSelect() - (0.5 * damage)) - (1 / 12));//���� ����

		return Finaldmg;
	}



	void LoopWarrior::pRegenHP() // ü�� ���   Tick();
	{
		if (plive == true) {
			pHp.nowHp += pRegen.regenHP;
		}
	}

	void LoopWarrior::checkStat()//ü�� ����
	{
		//hp ����
		pHp.maxHp = pHp.wepHp + pHp.minHp;

		if (pHp.nowHp > pHp.maxHp)
		{
			pHp.nowHp = pHp.maxHp;
		}

		if (pHp.nowHp < 0) 	//���ӿ���
		{
			plive = false;//�÷��̾� ����
			mAnimator->Play(L"WarrioraDeath", false);
		}
		//hp���� ��



	}

	void LoopWarrior::randStat()//�����ۿ� ���� ���� ������ Tick();
	{
		pAtt.nowAtt = rand() % (pAtt.maxAtt- pAtt.minAtt + 1) + pAtt.minAtt;

		pDef.nowDef = rand() % (pDef.maxDef- pDef.minDef +1) + pDef.minDef;

		pEvade.perEvade = pEvade.minEvade + pEvade.wepEvade; //ȸ����

		pCriticalPer.perCRITPERC = pCriticalPer.wepCRITPERC;

		pCounterAtk.perCounter = pCounterAtk.wepCounter;
	}

	void LoopWarrior::ppLevelUp(int mEXP)//������ ����
	{
		pExp.exp += mEXP; //���ͷκ��� ����ġ�� �޴´�.
		if (pExp.maxExp <= pExp.exp) 
		{
			pExp.level++;
			pExp.exp = 0;
		}

	}



	bool LoopWarrior::pAvoid()//���ϴ� Ȯ��
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

	bool LoopWarrior::pCounterAtt() // �ݰ� Ȯ��
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

	bool LoopWarrior::pCritical()//ũ��Ƽ�� Ȯ��
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