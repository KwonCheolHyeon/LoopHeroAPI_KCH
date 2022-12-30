#include "SpiderCocoon.h"
#include "chApplication.h"
#include "chInput.h"
#include "chImage.h"
#include "chResources.h"
#include "chCamera.h"
#include "chObject.h"
#include "GameMap.h"
#include "chTime.h"
#include"SpiderMini.h"
#include "chMiniIconStore.h"

namespace ch 
{
	SpiderCocoon::SpiderCocoon()
	{
		mImage = Resources::Load<Image>(L"SpiderCocoon", L"..\\Resources\\loophero\\Map\\GameObj\\SpiderCocoon.bmp");
	}
	SpiderCocoon::SpiderCocoon(Vector2 pos)
		: TileMapObject(pos)
	{
		mImage = Resources::Load<Image>(L"SpiderCocoon", L"..\\Resources\\loophero\\Map\\GameObj\\SpiderCocoon.bmp");
		mypos = pos;
		TwoDays = 0;
		CheckRoad();
	}
	SpiderCocoon::~SpiderCocoon()
	{
	}
	void SpiderCocoon::Initialize()
	{
		
	}
	void SpiderCocoon::Tick()
	{
		if (Time::mDays == 1)
		{
			TwoDays += 1;
			if (TwoDays == 2) 
			{
				SpiderSpawn();
				TwoDays = 0;
			}
		}
	}
	void SpiderCocoon::Render(HDC hdc)
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

	void SpiderCocoon::SpiderSpawn()
	{
		if (GameMap::roadTiles[findRoad.y][findRoad.x]->GetMonsterCount() < 5) //몬스터가 4마리 이하일때
		{
			//거미로 바꾸기
			GameMap::roadTiles[findRoad.y][findRoad.x]->SetMonsters(2);//몬스터 추가 하면서 타일에 몬스터 타입을 저장 슬라임이라 1
			int Gy = findRoad.y;
			int Gx = findRoad.x;
			
			MiniIconStore::gameObjsStore[Gy][Gx][GameMap::roadTiles[findRoad.y][findRoad.x]->GetMonsterCount()-1]
				= ch::object::Instantiate<MiniIconStore>(2,MapPosCalc(findRoad.y, findRoad.x), eColliderLayer::MiniIcon);
		}
	}
	
	void SpiderCocoon::CheckRoad()
	{
		if (GameMap::roadTiles[InMapPosCalc(mypos).y][(InMapPosCalc(mypos).x) + 1]->GetMapBaseCode() == 99) 
		{
			findRoad.y = InMapPosCalc(mypos).y;
			findRoad.x = (InMapPosCalc(mypos).x) + 1;
		}
		else if (GameMap::roadTiles[(InMapPosCalc(mypos).y )- 1][InMapPosCalc(mypos).x]->GetMapBaseCode() == 99) 
		{
			findRoad.y = (InMapPosCalc(mypos).y) - 1;
			findRoad.x = (InMapPosCalc(mypos).x);
		
		}
		else if (GameMap::roadTiles[InMapPosCalc(mypos).y][(InMapPosCalc(mypos).x) - 1]->GetMapBaseCode() == 99) 
		{
			findRoad.y = (InMapPosCalc(mypos).y);
			findRoad.x = (InMapPosCalc(mypos).x)-1;
		}
		else if (GameMap::roadTiles[(InMapPosCalc(mypos).y)+1][InMapPosCalc(mypos).x]->GetMapBaseCode() == 99)
		{
			findRoad.y = (InMapPosCalc(mypos).y)+1;
			findRoad.x = (InMapPosCalc(mypos).x);
		}
	}


	Vector2 SpiderCocoon::InMapPosCalc(Vector2 poss)
	{
		poss.y -= (TILE_SIZE * TILE_SCALE);
		int x = poss.x / (TILE_SIZE * TILE_SCALE);
		int y = poss.y / (TILE_SIZE * TILE_SCALE);

		Vector2 indexPos(x, y);

		return indexPos;
	}

	Vector2 SpiderCocoon::MapPosCalc(int y, int x)
	{
		Vector2 indexPos(x, y);
		indexPos.x = x * (TILE_SIZE * TILE_SCALE);
		indexPos.y = y * (TILE_SIZE * TILE_SCALE);
		indexPos.y += (TILE_SIZE * TILE_SCALE);

		Vector2 objectPos = indexPos;
		
		return objectPos;
	}

}
