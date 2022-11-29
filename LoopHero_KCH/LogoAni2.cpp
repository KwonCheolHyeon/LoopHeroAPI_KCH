#include "LogoAni2.h"
#include "chResources.h"
#include "chImage.h"
#include "chObject.h"
#include "chTime.h"

namespace ch 
{

	LogoAni2::LogoAni2()
		: mImage(nullptr)
	{
		SetPos({ 600 ,300 });
		SetScale({ 3.5f, 3.5f });
	}

	LogoAni2::~LogoAni2()
	{
	}

	void LogoAni2::Initialize()
	{
	}

	void LogoAni2::Tick()
	{
		GameObject::Tick();
		
	}

	void LogoAni2::Render(HDC hdc)
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

	void LogoAni2::SetImage(const std::wstring& key, const std::wstring& fileName)
	{
		std::wstring path = L"..\\Resources\\loophero\\TitleScene\\";
		path += fileName;

		mImage = Resources::Load<Image>(key, path);
	}

}