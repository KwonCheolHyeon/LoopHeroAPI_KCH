#include "LogoObject.h"
#include "chResources.h"
#include "chImage.h"
#include "chObject.h"
#include "chTime.h"

namespace ch 
{
	LogoObject::LogoObject()
		: mImage(nullptr)
		, imageLiveTime(0.0f)
	{

		SetPos({ 600 ,300});
		SetScale({ 3.5f, 3.5f });
	}
	LogoObject::~LogoObject()
	{
	}
	
	void LogoObject::Tick()
	{
		GameObject::Tick();
		imageLiveTime += Time::DeltaTime();

		if (imageLiveTime >= 5.0f )
		{
			this->Death();
			
		}

	}
	void LogoObject::Render(HDC hdc)
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
	void LogoObject::SetImage(const std::wstring& key, const std::wstring& fileName)
	{
		std::wstring path = L"..\\Resources\\loophero\\TitleScene\\";
		path += fileName;

		mImage = Resources::Load<Image>(key, path);

	}
	

	void LogoObject::Initialize()
	{

	}
}

