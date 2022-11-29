#include "Vampire_Mansion.h"
#include "chApplication.h"
#include "chInput.h"
#include "chImage.h"
#include "chResources.h"
#include "chCamera.h"

namespace ch
{
	Vampire_Mansion::Vampire_Mansion()
	{
		mImage = Resources::Load<Image>(L"Vampire_Mansion", L"..\\Resources\\loophero\\Map\\Cards\\Vampire_Mansion.bmp");
	}
	Vampire_Mansion::Vampire_Mansion(Vector2 pos)
		: GameObject(pos)
	{
		mImage = Resources::Load<Image>(L"Vampire_Mansion", L"..\\Resources\\loophero\\Map\\Cards\\Vampire_Mansion.bmp");
	}
	Vampire_Mansion::~Vampire_Mansion()
	{
	}
	void Vampire_Mansion::Initialize()
	{
	}
	void Vampire_Mansion::Tick()
	{
	}
	void Vampire_Mansion::Render(HDC hdc)
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