#include "Slime.h"
#include "chTime.h"
#include "chSceneManager.h"
#include "chInput.h"
#include "chMissile.h"
#include "chScene.h"
#include "chImage.h"
#include "chResources.h"
#include "chAnimator.h"
#include "chCollider.h"


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

		//������ �⺻ ü��
		mHP.baseHp = 13;
		mATT.baseStr = 3.3;
		mDEF.baseDef = 0;


	//���� ��������
		//mHP.nowHP = mHP.baseHp * LOOP; ���� HP 
		//mATT.nowStr = mATT.baseStr * LOOP; 
		//mDEF.nowDef = mDEF.baseDef * LOOP;
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

		attSpdChek += Time::DeltaTime();

		if (attSpdChek >= ( 1 / mSPD.spd)) //���ݼӵ�
		{
			mAttack();
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
	{//�÷��̾� ����

	}

	void Slime::mAttack()
	{
		//����

		attSpdChek = 0;
	}

	void Slime::takeDamage(double damage) //������ ������
	{
		mHP.nowHP -= calcDEF(damage);//������ ������
		
	}

	double Slime::calcDEF(double damage) // ���� ���
	{
		double Finaldmg = 0;

		Finaldmg = 0.5 * damage * (20.3125 / (18.75 + mDEF.nowDef - (0.5 * damage)) - (1 / 12));//���� ����

		return Finaldmg;
	}

	void Slime::ITEMs()
	{
		//������ ���� �Լ�
	}

}
