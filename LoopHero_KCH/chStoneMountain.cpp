#include "chStoneMountain.h"
#include "chApplication.h"
#include "chInput.h"
#include "chImage.h"
#include "chResources.h"
#include "chCamera.h"

namespace ch 
{
	StoneMountain::StoneMountain()
	{
		mImage = Resources::Load<Image>(L"stoneMountain", L"..\\Resources\\loophero\\Map\\GameObj\\StoneMountain.bmp");
	}
	StoneMountain::StoneMountain(Vector2 pos)
		: TileMapObject(pos)
	{
		mImage = Resources::Load<Image>(L"stoneMountain", L"..\\Resources\\loophero\\Map\\GameObj\\StoneMountain.bmp");
	}
	StoneMountain::~StoneMountain()
	{

	}

	void StoneMountain::Initialize()
	{

	}

	void StoneMountain::Tick()
	{

	}

	void StoneMountain::Render(HDC hdc)
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