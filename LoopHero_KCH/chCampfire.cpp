#include "chCampfire.h"
#include "chApplication.h"
#include "chInput.h"
#include "chImage.h"
#include "chResources.h"
#include "chCamera.h"

namespace ch 
{
	Campfire::Campfire()
	{
		mImage = Resources::Load<Image>(L"cemetery", L"..\\Resources\\loophero\\Map\\Cards\\cemetery.bmp");
	}
	Campfire::Campfire(Vector2 pos)
		: GameObject(pos)
	{
		mImage = Resources::Load<Image>(L"cemetery", L"..\\Resources\\loophero\\Map\\Cards\\cemetery.bmp");
	}
	Campfire::~Campfire()
	{
	}
	void Campfire::Initialize()
	{
	}
	void Campfire::Tick()
	{
	}
	void Campfire::Render(HDC hdc)
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