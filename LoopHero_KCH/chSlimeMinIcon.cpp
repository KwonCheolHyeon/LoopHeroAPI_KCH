#include "chSlimeMinIcon.h"

#include "chSceneManager.h"
#include "chScene.h"
#include "chImage.h"
#include "chResources.h"
#include "chAnimator.h"
#include "GameMap.h"
#include "TileMapObject.h"
#include "chCollider.h"


namespace ch 
{
	SlimeMinIcon::SlimeMinIcon()
	{
		SetName(L"Monster");
		SetPos({ 1600 / 2, 300 / 2 });
		SetScale({ 3.0f, 3.0f });
		mAnimator = new Animator();
		mAnimator->CreateAnimations(L"..\\Resources\\loophero\\monster\\Slime\\idle", L"SlimeIdle");
		mAnimator->Play(L"SlimeIdle", true);
		AddComponent(mAnimator);
	}
	SlimeMinIcon::SlimeMinIcon(Vector2 pos)
	{
		int i = 0;
		miniOffset[0] = { 5,5 };
		miniOffset[1] = { 45,5 };
		miniOffset[2] = { 5,45 };
		miniOffset[3] = { 45,45 };
		miniOffset[4] = { 25,25 };
	
		
		i = MonsterSetPos(pos);
		
		pos = miniOffset[i] + pos;

		SetName(L"SlimeMiniIcon");
		SetPos(pos);
		SetScale({ 1.0f, 1.0f });
		
		mAnimator = new Animator();
		mAnimator->CreateAnimations(L"..\\Resources\\loophero\\monster\\Monster_Icon\\Slime_Icon", L"SlimeMiniIdle");
		mAnimator->Play(L"SlimeMiniIdle", true);
		AddComponent(mAnimator);
		
	}

	SlimeMinIcon::~SlimeMinIcon()
	{

	}

	void SlimeMinIcon::Tick()
	{
		GameObject::Tick();

		Vector2 pos = GetPos();

		SetPos(pos);
	}

	void SlimeMinIcon::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	int SlimeMinIcon::MonsterSetPos(Vector2 pos)
	{
		int monsterCount = GameMap::roadTiles[InMapPosCalc(pos).y][InMapPosCalc(pos).x]->GetMonsterCount();



		return monsterCount-1;
	}

	Vector2 SlimeMinIcon::InMapPosCalc(Vector2 pos)
	{
		pos.y -= (TILE_SIZE * TILE_SCALE);
		int x = pos.x / (TILE_SIZE * TILE_SCALE);
		int y = pos.y / (TILE_SIZE * TILE_SCALE);

		Vector2 indexPos(x, y);

		return indexPos;
	}
}