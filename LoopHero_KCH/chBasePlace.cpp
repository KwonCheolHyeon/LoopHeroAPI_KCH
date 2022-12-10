#include "chBasePlace.h"
#include "chApplication.h"
#include "chInput.h"
#include "chImage.h"
#include "chResources.h"

namespace ch
{
	BasePlace::BasePlace()
	{
		mImage = Resources::Load<Image>(L"BasePlace", L"..\\Resources\\loophero\\Map\\Base\\placeBase.bmp");
	}

	BasePlace::BasePlace(Vector2 pos)
		: TileMapObject(pos)
	{
		mImage = Resources::Load<Image>(L"BasePlace", L"..\\Resources\\loophero\\Map\\Base\\placeBase.bmp");
	}

	BasePlace::~BasePlace()
	{
	}

	void BasePlace::Initialize()
	{
		/*
		TileBase :
		0 = 초기화
		1 = 건설가능 지역
		99 = 길
		*/
	}

	void BasePlace::Tick()
	{
	}

	void BasePlace::Render(HDC hdc)
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

}

