#include "newroad_3.h"
#include "chApplication.h"
#include "chInput.h"
#include "chImage.h"
#include "chResources.h"
#include "chCamera.h"

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
	}
	newroad_3::~newroad_3()
	{

	}
	void newroad_3::Initialize()
	{

	}
	void newroad_3::Tick()
	{

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
}