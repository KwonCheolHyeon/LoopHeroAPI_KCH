#include "FightPageOBJ.h"
#include "chResources.h"
#include "chImage.h"
#include "chObject.h"
#include "LoopWarrior.h"
#include "LoopMonster.h"
#include "FigjtPageTimeAni.h"
#include "pesochAni.h"
#include "WarriorMini.h"
#include "FightStart.h"
#include "GameMap.h"


namespace ch
{
	FightPageOBJ::FightPageOBJ(int y,int x)
		: mImage(nullptr)
	{
		GameObject::SetPos({ 280 ,(900 / 2)-350 });
		GameObject::SetScale({ 2.5f, 2.5f });
		tileYpos = y;
		tileXpos = x;
	}
	FightPageOBJ::FightPageOBJ(eUIType type)
	{
		GameObject::SetPos({ 280 ,(900 / 2) - 350 });
		GameObject::SetScale({ 2.5f, 2.5f });

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
		Vector2 pos = GameObject::GetPos();
		Vector2 scale = GameObject::GetScale();
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
		FightPageAniObj = ch::object::Instantiate<FigjtPageTimeAni>(eColliderLayer::TimeOBJ);
		playerPos = { 350,400 };

		Testplayer = ch::object::Instantiate<LoopWarrior>(playerPos,eColliderLayer::PlayerMonster);

		enemyPos[0] = { 782,343 }; //È¥ÀÚÀÖÀ»¶§
		enemyPos[1] = { 875,281.25f };
		enemyPos[2] = { 718.75f,343.75f };
		enemyPos[3] = { 875,437.5f };
		enemyPos[4] = { 718.75f,531.25f };
		enemyPos[5] = { 875,593.75f };
		
		prevFightCheck();
	}
	Monsters *FightPageOBJ::enemys[];
	LoopWarrior *FightPageOBJ::Testplayer;
	FigjtPageTimeAni* FightPageOBJ::FightPageAniObj;
	int FightPageOBJ::fightPageMonsterCount;

	void FightPageOBJ::FightStarts()
	{
	

	}

	void FightPageOBJ::objDeath()
	{
		FightPageAniObj->Death();
		Testplayer->Death();
		
		for (int i = 0; i < fightPageMonsterCount; i++)
		{
			if (enemys[i] != nullptr) 
			{
				enemys[i]->Death();
			}
		}
	}

	void FightPageOBJ::prevFightCheck()
	{
		int monsterCount = GameMap::roadTiles[tileYpos][tileXpos]->GetMonsterCount();
		fightPageMonsterCount = monsterCount;

		if (monsterCount == 1) 
		{
			for (int i = 0; i < monsterCount; i++)
			{
				int enemyTypeNum = GameMap::roadTiles[tileYpos][tileXpos]->GetMonsterType(i);

				enemys[i] = ch::object::Instantiate<Monsters>(enemyTypeNum, enemyPos[0], eColliderLayer::PlayerMonster);
			}
		}
		else 
		{
			for (int i = 0; i < monsterCount; i++)
			{
				int enemyTypeNum = GameMap::roadTiles[tileYpos][tileXpos]->GetMonsterType(i);

				enemys[i] = ch::object::Instantiate<Monsters>(enemyTypeNum, enemyPos[i + 1], eColliderLayer::PlayerMonster);
			}
		}
	}


}