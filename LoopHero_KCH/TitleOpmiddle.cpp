#include "TitleOpmiddle.h"
#include "chResources.h"
#include "chImage.h"
#include "chObject.h"
#include "chTime.h"
#include "titleStarBtn.h"

namespace ch
{
	TitleOpmiddle::TitleOpmiddle()
		: mImage(nullptr)
	{
		SetPos({ 650,-950 });
		SetScale({ 2.5f, 2.5f });
		ch::object::Instantiate<titleStarBtn>(eColliderLayer::UI);
	}

	TitleOpmiddle::~TitleOpmiddle()
	{
	}
	void TitleOpmiddle::Initialize()
	{
	}

	void TitleOpmiddle::Tick()
	{
		GameObject::Tick();
		Vector2 pos = GetPos();


		imageLiveTime += Time::DeltaTime();
		if (imageLiveTime >= 2.0f && imageLiveTime <= 4.7f)
		{
			pos.y += Time::DeltaTime() * 350;
		}
		if (imageLiveTime <= 2.0f && imageLiveTime <= 4.0f)
		{

		}

		SetPos(pos);
	}

	void TitleOpmiddle::Render(HDC hdc)
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

	void TitleOpmiddle::SetImage(const std::wstring& key, const std::wstring& fileName)
	{
		std::wstring path = L"..\\Resources\\loophero\\TitleScene\\menu\\";
		path += fileName;

		mImage = Resources::Load<Image>(key, path);
	}
}