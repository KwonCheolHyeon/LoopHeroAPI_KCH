#include "chMissile.h"
#include "chTime.h"
#include "chCollider.h"
#include "chCamera.h"
#include "chAnimator.h"
#include "chResources.h"
#include "chImage.h"

namespace ch
{
	Missile::Missile()
		: mSpeed(1.0f)
		, mAliveTime(5.0f)
	{
		SetPos({ 100.0f, 100.0f });
		SetScale({ 20.0f, 20.0f });

		Collider* col = new Collider();
		col->SetScale(Vector2(20.0f, 20.0f));

		AddComponent(col);
		if (mImage == nullptr)
		{
			mImage = Resources::Find<Image>(L"Player");
		}

		Animator* ani = new Animator();
		ani->CreateAnimation(L"Idle", mImage
			, Vector2(0.0f, 0.0f), Vector2(120.0f, 130.0f)
			, Vector2(5.0f, -20.0f), 3, 0.1f);

		ani->Play(L"Idle", true);

		AddComponent(ani);
		//Camera::SetTarget(this);
	}

	Missile::~Missile()
	{

	}

	void Missile::Tick()
	{
		GameObject::Tick();
		mAliveTime -= Time::DeltaTime();
		if (mAliveTime <= 0.0f)
		{
			this->Death();
		}

		Vector2 pos = GetPos();
		//pos.y -= 500.0f * Time::DeltaTime();
		SetPos(pos);
	}

	void Missile::Render(HDC hdc)
	{
		//Vector2 pos = GetPos();
		//Vector2 scale = GetScale();
		//pos = Camera::CalculatePos(pos);

		//Ellipse(hdc, pos.x - 10, pos.y - 10, pos.x + scale.x, pos.y + scale.y);

		GameObject::Render(hdc);
	}
	void Missile::OnCollisionEnter(Collider* other)
	{
		GameObject* gameObj = other->GetOwner();
		gameObj->Death();

		this->Death();
	}

	void Missile::OnCollisionStay(Collider* other)
	{
	}
	void Missile::OnCollisionExit(Collider* other)
	{
	}
}