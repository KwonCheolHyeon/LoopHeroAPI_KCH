#include "Cemetery.h"
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
	Cemetery::Cemetery()
	{
		mImage = Resources::Load<Image>(L"cemetery", L"..\\Resources\\loophero\\Map\\GameObj\\cemetery.bmp");
	}
	Cemetery::Cemetery(Vector2 pos)
		: TileMapObject(pos)
	{
		mImage = Resources::Load<Image>(L"cemetery", L"..\\Resources\\loophero\\Map\\GameObj\\cemetery.bmp");
		mypos = pos;
	}
	Cemetery::~Cemetery()
	{
	}
	void Cemetery::Initialize()
	{
	}
	void Cemetery::Tick()
	{
		if (Time::mDays == 1)
		{
			ThreeDays += 1;
			if (ThreeDays ==3 )
			{
				SkeletonSpawn();
				ThreeDays = 0;
			}
		}
	}
	void Cemetery::Render(HDC hdc)
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
	Vector2 Cemetery::InMapPosCalc(Vector2 pos)
	{
		pos.y -= (TILE_SIZE * TILE_SCALE);
		int x = pos.x / (TILE_SIZE * TILE_SCALE);
		int y = pos.y / (TILE_SIZE * TILE_SCALE);

		Vector2 indexPos(x, y);

		return indexPos;
	}
	void Cemetery::SkeletonSpawn()
	{
		if (GameMap::roadTiles[InMapPosCalc(mypos).y][InMapPosCalc(mypos).x]->GetMonsterCount() < 5) //몬스터가 4마리 이하일때 //최대 5마리 까지
		{

			GameMap::roadTiles[InMapPosCalc(mypos).y][InMapPosCalc(mypos).x]->SetMonsters(5);//몬스터 추가 하면서 타일에 몬스터 타입을 저장 슬라임이라 1
			int Gy = InMapPosCalc(mypos).y;
			int Gx = InMapPosCalc(mypos).x;

			MiniIconStore::gameObjsStore[Gy][Gx][GameMap::roadTiles[Gy][Gx]->GetMonsterCount() - 1]
				= ch::object::Instantiate<MiniIconStore>(5, mypos, eColliderLayer::MiniIcon);

		}
	}
}