#include "SpiderMini.h"
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

	SpideMini::SpideMini()
	{
	}

	SpideMini::SpideMini(Vector2 pos)
	{
		int i = 0;
		miniOffset[0] = { 5,5 };
		miniOffset[1] = { 45,5 };
		miniOffset[2] = { 5,45 };
		miniOffset[3] = { 45,45 };
		miniOffset[4] = { 25,25 };


		i = MonsterSetPos(pos);

		pos = miniOffset[i] + pos;

		SetName(L"SpiderIcon");
		SetPos(pos);
		SetScale({ 1.0f, 1.0f });

		mAnimator = new Animator();
		mAnimator->CreateAnimations(L"..\\Resources\\loophero\\monster\\Monster_Icon\\Spider_Icon", L"Spider_iIdle");
		mAnimator->Play(L"Spider_iIdle", true);
		AddComponent(mAnimator);
	}

	SpideMini::~SpideMini()
	{
	}

	void SpideMini::Tick()
	{
		GameObject::Tick();

		Vector2 pos = GetPos();

		SetPos(pos);
	}

	void SpideMini::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	int SpideMini::MonsterSetPos(Vector2 pos)
	{
		int monsterCount = GameMap::roadTiles[InMapPosCalc(pos).y][InMapPosCalc(pos).x]->GetMonsterCount();

		return monsterCount - 1;
	}

	Vector2 SpideMini::InMapPosCalc(Vector2 pos)
	{
		pos.y -= (TILE_SIZE * TILE_SCALE);
		int x = pos.x / (TILE_SIZE * TILE_SCALE);
		int y = pos.y / (TILE_SIZE * TILE_SCALE);

		Vector2 indexPos(x, y);

		return indexPos;
	}
}