#include "Grove.h"
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
	Grove::Grove()
	{
		mImage = Resources::Load<Image>(L"Grove", L"..\\Resources\\loophero\\Map\\GameObj\\Grove.bmp");
	}
	Grove::Grove(Vector2 pos)
		: TileMapObject(pos)
	{
		mImage = Resources::Load<Image>(L"Grove", L"..\\Resources\\loophero\\Map\\GameObj\\Grove.bmp");
		mypos = pos;
		TwoDays = 0;
		
	}
	Grove::~Grove()
	{
	}
	void Grove::Initialize()
	{

	}
	void Grove::Tick()
	{
		if (Time::mDays == 1)
		{
			TwoDays += 1;
			if (TwoDays == 2)
			{
				DogSpawn();
				TwoDays = 0;
			}
		}
	}
	void Grove::Render(HDC hdc)
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
	void Grove::DogSpawn()
	{
		if (GameMap::roadTiles[InMapPosCalc(mypos).y][InMapPosCalc(mypos).x]->GetMonsterCount() < 5) //몬스터가 4마리 이하일때 //최대 5마리 까지
		{

			GameMap::roadTiles[InMapPosCalc(mypos).y][InMapPosCalc(mypos).x]->SetMonsters(4);//몬스터 추가 하면서 타일에 몬스터 타입을 저장 슬라임이라 1
			int Gy = InMapPosCalc(mypos).y;
			int Gx = InMapPosCalc(mypos).x;

			MiniIconStore::gameObjsStore[Gy][Gx][GameMap::roadTiles[Gy][Gx]->GetMonsterCount() - 1]
				= ch::object::Instantiate<MiniIconStore>(4, mypos, eColliderLayer::MiniIcon);
		}
	}


	Vector2 Grove::InMapPosCalc(Vector2 pos)
	{
		pos.y -= (TILE_SIZE * TILE_SCALE);
		int x = pos.x / (TILE_SIZE * TILE_SCALE);
		int y = pos.y / (TILE_SIZE * TILE_SCALE);

		Vector2 indexPos(x, y);

		return indexPos;
	}



}