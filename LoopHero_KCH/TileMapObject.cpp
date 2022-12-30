#include "TileMapObject.h"
#include "chTime.h"
#include "chImage.h"
namespace ch 
{
	TileMapObject::TileMapObject()
		: mPos{ 0.0f, 0.0f }
		, mScale{ 1.0f, 1.0f }
	
	{
		mTileType = 0;
	}
	TileMapObject::TileMapObject(Vector2 position)
		: mPos(position)
		, mScale{ 1.0f, 1.0f }
	{
		monsterCount = 0;
		monsterIndex = 0;
		for (int i = 0; i < 5; i++) 
		{
			chMonsters[i] = 0;
		}
		
	}
	TileMapObject::~TileMapObject()
	{

	}
	void TileMapObject::Initialize()
	{

	}
	void TileMapObject::Tick()
	{

	}
	void TileMapObject::Render(HDC hdc)
	{

	}
	void TileMapObject::SetIndex(UINT index)
	{

	}

	void TileMapObject::SetMonsters(int monsIndex)
	{

		if (monsterCount == 0) 
		{
			chMonsters[0] = monsIndex;
			monsterCount++;//1개
		}
		else if(monsterCount == 1)
		{
			chMonsters[1] = monsIndex;
			monsterCount++;//2개
		}
		else if (monsterCount == 2)
		{
			chMonsters[2] = monsIndex;
			monsterCount++;//3개
		}
		else if (monsterCount == 3)
		{
			chMonsters[3] = monsIndex;
			monsterCount++;//4개
		}
		else if (monsterCount == 4)
		{
			chMonsters[4] = monsIndex;
			monsterCount++;
		}

	}

	void TileMapObject::clearMonsters()
	{
		for (int i = 0; i < 5; i++)
		{
			chMonsters[i] = 0;
		}
		monsterCount = 0;

	}

}