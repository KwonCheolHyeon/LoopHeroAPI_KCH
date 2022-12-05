#include "TileMapObject.h"
#include "chTime.h"
#include "chImage.h"
namespace ch 
{
	TileMapObject::TileMapObject()
		: mPos{ 0.0f, 0.0f }
		, mScale{ 1.0f, 1.0f }
	{

	}
	TileMapObject::TileMapObject(Vector2 position)
		: GameObject(position)
		, mAtlas(nullptr)
		, mY(-1)
		, mX(-1)
	{

	}
	TileMapObject::~TileMapObject()
	{
		
	}
	void TileMapObject::Initialize(Image* atlas, int index)
	{
		mIndex = index;
		if (atlas == nullptr || index < 0)
			return;

		mAtlas = atlas;

		int maxColumn = mAtlas->GetWidth() / TILE_SIZE;
		int maxRow = mAtlas->GetHeight() / TILE_SIZE;

		mY = index / maxColumn;
		mX = index % maxColumn;

	}
	void TileMapObject::Tick()
	{

	}
	void TileMapObject::Render(HDC hdc)
	{
		if (mAtlas == nullptr)
			return;

	

	}
	void TileMapObject::SetIndex(UINT index)
	{
		mIndex = index;

		int maxColumn = mAtlas->GetWidth() / TILE_SIZE;
		int maxRow = mAtlas->GetHeight() / TILE_SIZE;

		mY = index / maxColumn;
		mX = index % maxColumn;
	}
}