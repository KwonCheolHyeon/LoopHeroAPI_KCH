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
		
	}

	LoopWarrior::~LoopWarrior()
	{

	}

	void LoopWarrior::Tick()
	{
		playerRegenTime += (Time::DeltaTime() * gameSpeed); // 1�ʴ� ���� �ð�;
		GameObject::Tick();
		Vector2 pos = GetPos();
		Vector2 scale = GetScale();

		SetPos(pos);

		if (KEY_DOWN(eKeyCode::I))
		{
			mAnimator->Play(L"WarriorIdle", false);
		}

		if (KEY_DOWN(eKeyCode::A))
		{
			mAnimator->Play(L"Warriorattack", false);
		}

		if (KEY_DOWN(eKeyCode::H))
		{
			mAnimator->Play(L"WarrioraHurt", false);
		}

		if (KEY_DOWN(eKeyCode::D))
		{
			mAnimator->Play(L"WarrioraDeath", false);
		}
		

		if(playerRegenTime >= 1.0f)//�ʴ� ȸ��
		{
			pRegenHP();
			playerRegenTime = 0;
		}
		
	}

	void LoopWarrior::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	void LoopWarrior::setTarget() //������ Ÿ�� ����
	{


	}

	void LoopWarrior::Attack() // ����
	{
		if (pCritical()) //ũ��Ƽ�� 
		{
		
		}
		else 
		{
		
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
			pHp.nowHp -= calcDEF(damage);//������ ������
			if ( pCounterAtt() ) //�ݰ�Ȯ�� ����ϰ� ������ ����
			{
				Attack();
			}
		}
		
	}

	double LoopWarrior::calcDEF(double damage)//���� ���
	{
		double Finaldmg = 0;

		Finaldmg = 0.5 * damage * (20.3125 / (18.75 + pDef.nowDef - (0.5 * damage)) - (1 / 12));//���� ����

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
		pAtt.nowAtt = rand() % (pAtt.maxAtt- pAtt.minAtt) + pAtt.minAtt;

		pDef.nowDef = rand() % (pDef.maxDef- pDef.minDef) + pDef.minDef;

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

	

}