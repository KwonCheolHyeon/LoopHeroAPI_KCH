#include "LogoAni1.h"
#include "chResources.h"
#include "chImage.h"
#include "chObject.h"
#include "chTime.h"
namespace ch 
{
	LogoAni1::LogoAni1() //타이틀씬에 루프히어로 로고
		: mImage(nullptr)
	{
		SetPos({ 550,200});
		SetScale({ 2.5f, 2.5f });
		this->m_Blend.SourceConstantAlpha = 0;
	}
	LogoAni1::~LogoAni1()
	{

	}
	void LogoAni1::Initialize()
	{
	}
	void LogoAni1::Tick()
	{
		GameObject::Tick();
		Vector2 pos = GetPos();
		

		imageLiveTime += Time::DeltaTime();
		if (imageLiveTime >= 2.0f && imageLiveTime <= 4.7f) 
		{
			pos.y -=  Time::DeltaTime()*100;
		}
		if (imageLiveTime <= 2.0f && imageLiveTime <= 4.0f)
		{
			
		}

		SetPos(pos);
	}

	void LogoAni1::Render(HDC hdc)
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
	void LogoAni1::SetImage(const std::wstring& key, const std::wstring& fileName)
	{
		std::wstring path = L"..\\Resources\\loophero\\TitleScene\\";
		path += fileName;

		mImage = Resources::Load<Image>(key, path);
	}
}

