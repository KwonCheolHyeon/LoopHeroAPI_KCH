#include "chDayOBJ.h"
#include "chResources.h"
#include "chImage.h"

namespace ch
{
	chDayOBJ::chDayOBJ()
		: mImage(nullptr)
	{
		SetPos(Vector2::Zero);
		SetScale({ 2.5f,2.5f });
	}
	chDayOBJ::~chDayOBJ()
	{
	}
	void chDayOBJ::Initialize()
	{
	}
	void chDayOBJ::Tick()
	{
		GameObject::Tick();
	}
	void chDayOBJ::Render(HDC hdc)
	{
		Vector2 pos = GetPos();
		Vector2 scale = GetScale();
		Vector2 finalPos = pos;

		Vector2 rect;
		rect.x = mImage->GetWidth() * scale.x;
		rect.y = mImage->GetHeight() * scale.y;

		TransparentBlt(hdc, finalPos.x, finalPos.y, rect.x, rect.y
			, mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
			, RGB(255, 0, 255));

		GameObject::Render(hdc);
	}
	void chDayOBJ::SetImage(const std::wstring& key, const std::wstring& fileName)
	{
		std::wstring path = L"..\\Resources\\loophero\\MainGame\\BackGroundOBJ\\day\\";
		path += fileName;

		mImage = Resources::Load<Image>(key, path);
	}
}