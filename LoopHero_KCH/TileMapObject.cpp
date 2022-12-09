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
}