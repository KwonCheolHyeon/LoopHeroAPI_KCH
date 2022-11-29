#include "newroad_0.h"
#include "chApplication.h"
#include "chInput.h"
#include "chImage.h"
#include "chResources.h"
#include "chCamera.h"

namespace ch 
{
	newroad_0::newroad_0()
	{
		mImage = Resources::Load<Image>(L"Road0", L"..\\Resources\\loophero\\Map\\Road\\newroad_0.bmp");
	}
	newroad_0::newroad_0(Vector2 pos)
		: GameObject(pos)
	{
		mImage = Resources::Load<Image>(L"Road0", L"..\\Resources\\loophero\\Map\\Road\\newroad_0.bmp");
	}
	newroad_0::~newroad_0()
	{

	}
	void newroad_0::Initialize()
	{

	}
	void newroad_0::Tick()
	{

	}
	void newroad_0::Render(HDC hdc)
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