#include "FightPageOBJ.h"
#include "chResources.h"
#include "chImage.h"
#include "chObject.h"
#include "LoopWarrior.h"
#include "Slime.h"
#include "FigjtPageTimeAni.h"
#include "pesochAni.h"
#include "WarriorMini.h"
#include "FightStart.h"

namespace ch
{
	FightPageOBJ::FightPageOBJ(int y,int x)
		: mImage(nullptr)
	{
		SetPos({ 280 ,(900 / 2)-350 });
		SetScale({ 2.5f, 2.5f });
		tileYpos = y;
		tileXpos = x;
	}
	FightPageOBJ::~FightPageOBJ()
	{
		
		
		
	}
	
	void FightPageOBJ::Tick()
	{
		GameObject::Tick();
	}
	void FightPageOBJ::Render(HDC hdc)
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

	void FightPageOBJ::SetImage(const std::wstring& key, const std::wstring& fileName)
	{
		std::wstring path = L"..\\Resources\\loophero\\FightPage\\";
		path += fileName;

		mImage = Resources::Load<Image>(key, path);
	}
	
	void FightPageOBJ::Initialize()
	{
		ch::object::Instantiate<FigjtPageTimeAni>(eColliderLayer::Tile);


		/*
		ch::object::Instantiate<LoopWarrior>(eColliderLayer::Player);
		ch::object::Instantiate<Slime>(eColliderLayer::Monster);
		*/
	}

	void FightPageOBJ::FightStarts()
	{



	}


}