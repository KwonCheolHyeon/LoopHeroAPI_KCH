#include "newroad_4.h"
#include "chApplication.h"
#include "chInput.h"
#include "chImage.h"
#include "chResources.h"
#include "chCamera.h"

namespace ch
{
	newroad_4::newroad_4()
	{
		mImage = Resources::Load<Image>(L"Road4", L"..\\Resources\\loophero\\Map\\Road\\newroad_4.bmp");
	}
	newroad_4::newroad_4(Vector2 pos)
		: TileMapObject(pos)
	{
		mImage = Resources::Load<Image>(L"Road4", L"..\\Resources\\loophero\\Map\\Road\\newroad_4.bmp");
	}
	newroad_4::~newroad_4()
	{

	}
	void newroad_4::Initialize()
	{

	}
	void newroad_4::Tick()
	{
		
	}
	void newroad_4::Render(HDC hdc)
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