#include "Vampire_Mansion.h"
#include "chApplication.h"
#include "chInput.h"
#include "chImage.h"
#include "chResources.h"
#include "chCamera.h"
#include "chObject.h"
#include "GameMap.h"
#include "chTime.h"
#include "chMiniIconStore.h"

namespace ch
{
	Vampire_Mansion::Vampire_Mansion()
	{
		mImage = Resources::Load<Image>(L"Vampire_Mansion", L"..\\Resources\\loophero\\Map\\GameObj\\Vampire_Mansion.bmp");
	}
	Vampire_Mansion::Vampire_Mansion(Vector2 pos)
		: TileMapObject(pos)
	{
		mImage = Resources::Load<Image>(L"Vampire_Mansion", L"..\\Resources\\loophero\\Map\\GameObj\\Vampire_Mansion.bmp");
		
		mypos = pos;
		ThreeDays = 0;
		CheckRoad();
	}
	Vampire_Mansion::~Vampire_Mansion()
	{
	}
	void Vampire_Mansion::Initialize()
	{
	}
	void Vampire_Mansion::Tick()
	{
		if (Time::mDays == 1)
		{
			ThreeDays += 1;
			if (ThreeDays == 3)
			{
				VampireSpawn();
				ThreeDays = 0;
			}
		}
	}
	void Vampire_Mansion::Render(HDC hdc)
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
	Vector2 Vampire_Mansion::InMapPosCalc(Vector2 poss)
	{
		poss.y -= (TILE_SIZE * TILE_SCALE);
		int x = poss.x / (TILE_SIZE * TILE_SCALE);
		int y = poss.y / (TILE_SIZE * TILE_SCALE);

		Vector2 indexPos(x, y);

		return indexPos;
	}
	Vector2 Vampire_Mansion::MapPosCalc(int y, int x)
	{
		Vector2 indexPos(x, y);
		indexPos.x = x * (TILE_SIZE * TILE_SCALE);
		indexPos.y = y * (TILE_SIZE * TILE_SCALE);
		indexPos.y += (TILE_SIZE * TILE_SCALE);

		Vector2 objectPos = indexPos;

		return objectPos;
	}
	void Vampire_Mansion::CheckRoad()
	{
		if (GameMap::roadTiles[InMapPosCalc(mypos).y][(InMapPosCalc(mypos).x) + 1]->GetMapBaseCode() == 99)
		{
			findRoad.y = InMapPosCalc(mypos).y;
			findRoad.x = (InMapPosCalc(mypos).x) + 1;
		}
		else if (GameMap::roadTiles[(InMapPosCalc(mypos).y) - 1][InMapPosCalc(mypos).x]->GetMapBaseCode() == 99)
		{
			findRoad.y = (InMapPosCalc(mypos).y) - 1;
			findRoad.x = (InMapPosCalc(mypos).x);

		}
		else if (GameMap::roadTiles[InMapPosCalc(mypos).y][(InMapPosCalc(mypos).x) - 1]->GetMapBaseCode() == 99)
		{
			findRoad.y = (InMapPosCalc(mypos).y);
			findRoad.x = (InMapPosCalc(mypos).x) - 1;
		}
		else if (GameMap::roadTiles[(InMapPosCalc(mypos).y) + 1][InMapPosCalc(mypos).x]->GetMapBaseCode() == 99)
		{
			findRoad.y = (InMapPosCalc(mypos).y) + 1;
			findRoad.x = (InMapPosCalc(mypos).x);
		}
	}
	void Vampire_Mansion::VampireSpawn()
	{
		if (GameMap::roadTiles[findRoad.y][findRoad.x]->GetMonsterCount() < 5) //몬스터가 4마리 이하일때
		{
			//거미로 바꾸기
			GameMap::roadTiles[findRoad.y][findRoad.x]->SetMonsters(3);//몬스터 추가 하면서 타일에 몬스터 타입을 저장 슬라임이라 1
			int Gy = findRoad.y;
			int Gx = findRoad.x;

			MiniIconStore::gameObjsStore[Gy][Gx][GameMap::roadTiles[findRoad.y][findRoad.x]->GetMonsterCount() - 1]
				= ch::object::Instantiate<MiniIconStore>(3, MapPosCalc(findRoad.y, findRoad.x), eColliderLayer::MiniIcon);
		}

	}
}