#include "newroad_3.h"
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
	newroad_3::newroad_3()
	{
		mImage = Resources::Load<Image>(L"Road3", L"..\\Resources\\loophero\\Map\\Road\\newroad_3.bmp");
	}
	newroad_3::newroad_3(Vector2 pos)
		: TileMapObject(pos)
	{
		mImage = Resources::Load<Image>(L"Road3", L"..\\Resources\\loophero\\Map\\Road\\newroad_3.bmp");
		mypos = pos;
		srand(time(NULL));
	}
	newroad_3::~newroad_3()
	{

	}
	void newroad_3::Initialize()
	{

	}
	void newroad_3::Tick()
	{
		if (Time::mDays == 1)
		{
			SlimeSpawn();
		}
	}
	void newroad_3::Render(HDC hdc)
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

	void newroad_3::SlimeSpawn()
	{

		if (GameMap::roadTiles[InMapPosCalc(mypos).y][InMapPosCalc(mypos).x]->GetMonsterCount() < 5) //���Ͱ� 5���� �����϶�
		{
			int random = rand() % 100 + 1; // 1~100;
			if (random >= 96)
			{
				GameMap::roadTiles[InMapPosCalc(mypos).y][InMapPosCalc(mypos).x]->SetMonsters(1);//���� �߰� �ϸ鼭 Ÿ�Ͽ� ���� Ÿ���� ���� �������̶� 1
				int Gy = InMapPosCalc(mypos).y;
				int Gx = InMapPosCalc(mypos).x;

				MiniIconStore::gameObjsStore[Gy][Gx][GameMap::roadTiles[Gy][Gx]->GetMonsterCount()-1]
					= ch::object::Instantiate<MiniIconStore>(1, mypos, eColliderLayer::MiniIcon);
			}
		}
	}

	Vector2 newroad_3::InMapPosCalc(Vector2 pos)
	{
		pos.y -= (TILE_SIZE * TILE_SCALE);
		int x = pos.x / (TILE_SIZE * TILE_SCALE);
		int y = pos.y / (TILE_SIZE * TILE_SCALE);

		Vector2 indexPos(x, y);

		return indexPos;
	}
}