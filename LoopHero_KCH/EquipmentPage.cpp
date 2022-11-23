#include "EquipmentPage.h"
#include "chSceneManager.h"
#include "chScene.h"
#include "chImage.h"
#include "chResources.h"



namespace ch {
	EquipmentPage::EquipmentPage()
		: mImage(nullptr)
	{
		SetPos({1600-370,0});
		SetScale({ 2.5f,2.5f });
	}
	EquipmentPage::~EquipmentPage()
	{
	}
	void EquipmentPage::Initialize()
	{
		
	}
	void EquipmentPage::Tick()
	{
		GameObject::Tick();
	}
	void EquipmentPage::Render(HDC hdc)
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

	void EquipmentPage::SetImage(const std::wstring& key, const std::wstring& fileName)
	{
		std::wstring path = L"..\\Resources\\loophero\\EquipmentPage\\";
		path += fileName;

		mImage = Resources::Load<Image>(key, path);
	}
}