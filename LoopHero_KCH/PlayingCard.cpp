#include "PlayingCard.h"
#include "chResources.h"
#include "chImage.h"
#include "chCollider.h"
#include "chInput.h"
#include "GameMap.h"

namespace ch 
{
	PlayingCard::PlayingCard()
		: mBGImage(nullptr)
		, mCardImage(nullptr)
		, mTileType(1)
	{
		SetPos(Vector2::Zero);
		SetScale({ 2.5f,2.5f });

		Collider* collider = new Collider();
		AddComponent(collider);

		
		collider->SetOffset(Vector2(50, 80));
	}
	PlayingCard::~PlayingCard()
	{
	}
	void PlayingCard::Initialize()
	{

	}
	void PlayingCard::Tick()
	{
		GameObject::Tick();
		
	}
	void PlayingCard::Render(HDC hdc)
	{
		Vector2 pos = GetPos();
		Vector2 scale = GetScale();
		Vector2 finalPos = pos;

		Vector2 rect;
		rect.x = mBGImage->GetWidth() * scale.x;
		rect.y = mBGImage->GetHeight() * scale.y;

		Vector2 rectCard;
		rectCard.x = mCardImage->GetWidth() * 2.5f;
		rectCard.y = mCardImage->GetHeight() * 2.5f;

		

		TransparentBlt(hdc, finalPos.x, finalPos.y, rect.x, rect.y
			, mBGImage->GetDC(), 0, 0, mBGImage->GetWidth(), mBGImage->GetHeight()
			, RGB(255, 0, 255));

		TransparentBlt(hdc, finalPos.x + 15, finalPos.y + 20, rectCard.x , rectCard.y
			, mCardImage->GetDC(), 0, 0, mCardImage->GetWidth(), mCardImage->GetHeight()
			, RGB(255, 0, 255));

		GameObject::Render(hdc);
	}

	void PlayingCard::OnCollisionEnter(Collider* other)
	{
	}

	void PlayingCard::OnCollisionStay(Collider* other)
	{
		if (KEY_DOWN(eKeyCode::LBTN))
		{
			GameMap::Instance().SetTileType(mTileType);
		}
	}

	void PlayingCard::OnCollisionExit(Collider* other)
	{
	}

	void PlayingCard::SetBGImage(const std::wstring& key, const std::wstring& fileName)
	{
		std::wstring path = L"..\\Resources\\loophero\\MainGame\\Card\\";
		path += fileName;

		mBGImage = Resources::Load<Image>(key, path);
	}

	void PlayingCard::SetCardImage(const std::wstring& key, const std::wstring& fileName)
	{
		std::wstring path = L"..\\Resources\\loophero\\MainGame\\CardImage\\";
		path += fileName;

		mCardImage = Resources::Load<Image>(key, path);
	}
}