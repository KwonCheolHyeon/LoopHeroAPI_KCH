#include "newroad_2.h"
#include "chApplication.h"
#include "chInput.h"
#include "chImage.h"
#include "chResources.h"
#include "chCamera.h"

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
	}
	newroad_2::~newroad_2()
	{

	}
	void newroad_2::Initialize()
	{

	}
	void newroad_2::Tick()
	{

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
}