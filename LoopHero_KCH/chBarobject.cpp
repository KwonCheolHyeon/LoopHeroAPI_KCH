#include "chBarobject.h"
#include "chResources.h"
#include "chImage.h"
#include "chObject.h"
#include "chTime.h"
#include "titleStarBtn.h"
#include "WarriorMini.h"
#include "GameMap.h"

namespace ch {
	Barobject::Barobject(int type)
		: mImage(nullptr)
	{
		if (type == 1) //hp
		{
			SetPos({ 1364,292 });
			SetScale({ 1,1 });
			types = type;
		}
		else if (type == 2) //day
		{
			SetPos({ 40,8 });
			SetScale({ 1,1 });
			types = type;
		}
		else if (type == 3) //boss
		{
			SetPos({ 39,47 });
			SetScale({ 1,1 });
			types = type;
		}
		
	}

	Barobject::~Barobject()
	{
	}
	void Barobject::Initialize()
	{
	}

	void Barobject::Tick()
	{
		GameObject::Tick();

		Vector2 pos = GetPos();

		SetPos(pos);
	}

	void Barobject::Render(HDC hdc)
	{
		if (types == 1) 
		{
			Vector2 pos = GetPos();
			Vector2 scale = GetScale();
			Vector2 finalPos = pos;

			Vector2 rect;
			rect.x = mImage->GetWidth() * scale.x;
			rect.y = mImage->GetHeight() * scale.y;

			
			float chX = WarriorMini::miniNowHp;//hp
			float xRatio = (chX / WarriorMini::miniHP); //현재 체력 / 최대 체력
			
			if (xRatio >= 1) {
				xRatio = 1;
			}

			TransparentBlt(hdc, finalPos.x, finalPos.y, rect.x * xRatio, rect.y
				, mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
				, RGB(255, 0, 255));

			GameObject::Render(hdc);
		
		}
		else if (types == 2) 
		{
			Vector2 pos = GetPos();
			Vector2 scale = GetScale();
			Vector2 finalPos = pos;

			Vector2 rect;
			rect.x = mImage->GetWidth() * scale.x;
			rect.y = mImage->GetHeight() * scale.y;

			float chX = Time::mDayTime;//day
			float xRatio = (chX / 15.0f);
			TransparentBlt(hdc, finalPos.x, finalPos.y, rect.x * xRatio, rect.y
				, mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
				, RGB(255, 0, 255));

			GameObject::Render(hdc);
		
		}
		else if (types == 3) 
		{
			Vector2 pos = GetPos();
			Vector2 scale = GetScale();
			Vector2 finalPos = pos;

			Vector2 rect;
			rect.x = mImage->GetWidth() * scale.x;
			rect.y = mImage->GetHeight() * scale.y;

			float chX = GameMap::tileBossCount; //day
			if (chX >= 20) 
			{
				chX = 20;
			}
			float xRatio = (chX / 20.0f);
			TransparentBlt(hdc, finalPos.x, finalPos.y, rect.x * xRatio, rect.y
				, mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
				, RGB(255, 0, 255));

			GameObject::Render(hdc);
		
		}
		
	}

	void Barobject::SetImage(const std::wstring& key, const std::wstring& fileName)
	{
		std::wstring path = L"..\\Resources\\loophero\\hud\\";
		path += fileName;

		mImage = Resources::Load<Image>(key, path);
	}

}