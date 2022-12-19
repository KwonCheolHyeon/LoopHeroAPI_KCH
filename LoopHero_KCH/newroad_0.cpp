#include "newroad_0.h"
#include "chApplication.h"
#include "chInput.h"
#include "chImage.h"
#include "chResources.h"
#include "chCamera.h"
#include "chObject.h"
#include "chSlimeMinIcon.h"
#include "GameMap.h"
#include "chTime.h"



namespace ch 
{
	
	newroad_0::newroad_0()
	{
		mImage = Resources::Load<Image>(L"Road0", L"..\\Resources\\loophero\\Map\\Road\\newroad_0.bmp");
	}
	newroad_0::newroad_0(Vector2 pos)
		: TileMapObject(pos)
	{
		mImage = Resources::Load<Image>(L"Road0", L"..\\Resources\\loophero\\Map\\Road\\newroad_0.bmp");
		mypos = pos;
	}
	newroad_0::~newroad_0()
	{

	}
	void newroad_0::Initialize()
	{

	}

	void newroad_0::Tick()
	{
		
		if (Time::mDays == 1)
		{
			SlimeSpawn();
		}

	}

	void newroad_0::Render(HDC hdc)
	{
		Vector2 pos = GetPos();
		Vector2 scale = GetScale();

		Vector2 rect;
		rect.x = mImage->GetWidth() * TILE_SCALE;
		rect.y = mImage->GetHeight() * TILE_SCALE;

		float dif = (mImage->GetHeight() - TILE_SIZE);
		dif *= TILE_SCALE;
		pos.y -= dif;

		TransparentBlt(hdc, pos.x, pos.y, rect.x, rect.y
			, mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
			, RGB(255, 0, 255));
	}

	void newroad_0::SlimeSpawn()
	{
		int random = rand() % 100 + 1; // 1~100;
		if (random >= 96)
		{
			ch::object::Instantiate<SlimeMinIcon>(mypos, eColliderLayer::Road);

		}
	}

	Vector2 newroad_0::MapPosCalc(Vector2 pos)
	{
		int x = pos.x;
		int y = pos.y;
		Vector2 indexPos(x, y);
		indexPos.x = x * (TILE_SIZE * TILE_SCALE);
		indexPos.y = y * (TILE_SIZE * TILE_SCALE);
		indexPos.y += (TILE_SIZE * TILE_SCALE);

		Vector2 objectPos = indexPos;

		return objectPos;
	}

}