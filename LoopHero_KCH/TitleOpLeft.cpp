#include "TitleOpLeft.h"
#include "chResources.h"
#include "chImage.h"
#include "chObject.h"
#include "chTime.h"

namespace ch 
{
	TitleOpLeft::TitleOpLeft()
		: mImage(nullptr)
	{
		SetPos({ -550,0 });
		SetScale({ 2.5f, 2.5f });
	}
	TitleOpLeft::~TitleOpLeft()
	{
	}
	void TitleOpLeft::Initialize()
	{
	}
	void TitleOpLeft::Tick()
	{
		GameObject::Tick();
		Vector2 pos = GetPos();


		imageLiveTime += Time::DeltaTime();
		if (imageLiveTime >= 2.0f && imageLiveTime <= 4.7f)
		{
			pos.x += Time::DeltaTime() * 200;
		}
		
		SetPos(pos);
	}
	void TitleOpLeft::Render(HDC hdc)
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
	void TitleOpLeft::SetImage(const std::wstring& key, const std::wstring& fileName)
	{
		std::wstring path = L"..\\Resources\\loophero\\TitleScene\\menu\\";
		path += fileName;

		mImage = Resources::Load<Image>(key, path);
	}
}