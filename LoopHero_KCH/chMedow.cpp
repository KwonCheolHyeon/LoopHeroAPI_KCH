#include "chMedow.h"
#include "chApplication.h"
#include "chInput.h"
#include "chImage.h"
#include "chResources.h"
#include "chCamera.h"
namespace ch {
	Medow::Medow()
	{
		mImage = Resources::Load<Image>(L"Medow", L"..\\Resources\\loophero\\Map\\Cards\\Medow.bmp");
	}
	Medow::Medow(Vector2 pos)
		: TileMapObject(pos)
	{
		mImage = Resources::Load<Image>(L"Medow", L"..\\Resources\\loophero\\Map\\Cards\\Medow.bmp");
	}
	Medow::~Medow()
	{

	}
	void Medow::Initialize()
	{

	}
	void Medow::Tick()
	{

	}
	void Medow::Render(HDC hdc)
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