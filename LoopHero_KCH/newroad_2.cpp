#include "newroad_2.h"
#include "chApplication.h"
#include "chInput.h"
#include "chImage.h"
#include "chResources.h"
#include "chCamera.h"
#include "chObject.h"
#include "chMiniIconStore.h"
#include "GameMap.h"
#include "chTime.h"

namespace ch
{
	newroad_2::newroad_2()
	{
		mImage = Resources::Load<Image>(L"Road2", L"..\\Resources\\loophero\\Map\\Road\\newroad_2.bmp");
	}
	newroad_2::newroad_2(Vector2 pos)
		: TileMapObject(pos)
	{
		mImage = Resources::Load<Image>(L"Road2", L"..\\Resources\\loophero\\Map\\Road\\newroad_2.bmp");


		mypos = pos;
		srand(time(NULL));
	}
	newroad_2::~newroad_2()
	{

	}
	void newroad_2::Initialize()
	{

	}
	void newroad_2::Tick()
	{
		if (Time::mDays == 1)
		{
			SlimeSpawn();
		}
	}
	void newroad_2::Render(HDC hdc)
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

	void newroad_2::SlimeSpawn()
	{
		if (GameMap::roadTiles[InMapPosCalc(mypos).y][InMapPosCalc(mypos).x]->GetMonsterCount() < 5 && GameMap::roadTiles[InMapPosCalc(mypos).y][InMapPosCalc(mypos).x]->GetTileType() != 100) //몬스터가 5마리 이하일때
		{
			int random = rand() % 100 + 1; // 1~100;
			if (random >= 96)
			{
				GameMap::roadTiles[InMapPosCalc(mypos).y][InMapPosCalc(mypos).x]->SetMonsters(1);//몬스터 추가 하면서 타일에 몬스터 타입을 저장 슬라임이라 1
				int Gy = InMapPosCalc(mypos).y;
				int Gx = InMapPosCalc(mypos).x;

				MiniIconStore::gameObjsStore[Gy][Gx][GameMap::roadTiles[Gy][Gx]->GetMonsterCount()-1]
					= ch::object::Instantiate<MiniIconStore>(1, mypos, eColliderLayer::MiniIcon);
			}
		}
	}

	Vector2 newroad_2::InMapPosCalc(Vector2 pos)
	{
		pos.y -= (TILE_SIZE * TILE_SCALE);
		int x = pos.x / (TILE_SIZE * TILE_SCALE);
		int y = pos.y / (TILE_SIZE * TILE_SCALE);

		Vector2 indexPos(x, y);

		return indexPos;
	}
}