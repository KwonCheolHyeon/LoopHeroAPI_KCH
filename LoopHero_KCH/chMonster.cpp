#include "chMonster.h"

#include "chTime.h"
#include "chSceneManager.h"
#include "chInput.h"
#include "chMissile.h"
#include "chScene.h"
#include "chImage.h"
#include "chResources.h"
#include "chAnimator.h"
#include "chCollider.h"
#include "chCamera.h"

namespace ch
{
	Monster::Monster()
		: mTime(0.0f)
	{
		SetName(L"Monster");
		SetPos({ 1600 / 2, 300 / 2 });
		SetScale({ 3.0f, 3.0f });

		if (mImage == nullptr)
		{
			mImage = Resources::Load<Image>(L"Monster", L"..\\Resources\\Image\\Monster.bmp");
		}

		//AddComponent(new Animator());
		AddComponent(new Collider());
	}

	Monster::Monster(Vector2 position)
		: mTime(0.0f)
	{
		SetName(L"Monster");
		SetPos(position);
		SetScale({ 3.0f, 3.0f });

		if (mImage == nullptr)
		{
			mImage = Resources::Load<Image>(L"Monster", L"..\\Resources\\Image\\Monster.bmp");
		}

		//AddComponent(new Animator());
		AddComponent(new Collider());
	}

	Monster::~Monster()
	{

	}

	void Monster::Tick()
	{
		GameObject::Tick();

		Vector2 pos = GetPos();

		SetPos(pos);

		//mTime += Time::DeltaTime();

		//if (mTime > 5.0f)
		//{
		//	pos.x -= 30;
		//	SetPos(pos);
		//	mTime = 0.0f;
		//}
	}

	void Monster::Render(HDC hdc)
	{
		Vector2 pos = GetPos();
		Vector2 scale = GetScale();

		Vector2 finalPos;
		finalPos.x = (pos.x - mImage->GetWidth() * (scale.x / 2.0f));
		finalPos.y = (pos.y - mImage->GetHeight() * (scale.y / 2.0f));

		Vector2 rect;
		rect.x = mImage->GetWidth() * scale.x;
		rect.y = mImage->GetHeight() * scale.y;

		finalPos = Camera::CalculatePos(finalPos);

		TransparentBlt(hdc, finalPos.x, finalPos.y, rect.x, rect.y
			, mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
			, RGB(255, 0, 255));

		GameObject::Render(hdc);
	}
	void Monster::OnCollisionEnter(Collider* other)
	{
	}
	void Monster::OnCollisionStay(Collider* other)
	{
	}
	void Monster::OnCollisionExit(Collider* other)
	{
	}
}
