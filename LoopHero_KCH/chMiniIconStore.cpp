#include "chMiniIconStore.h"
#include "chSceneManager.h"
#include "chScene.h"
#include "chImage.h"
#include "chResources.h"
#include "chAnimator.h"
#include "GameMap.h"
#include "TileMapObject.h"
#include "chCollider.h"
#include "WarriorMini.h"
namespace ch 
{
    MiniIconStore::MiniIconStore(Vector2 pos)
    {
    }

    MiniIconStore::MiniIconStore(int index, Vector2 pos)
    {
        if (index == 1) 
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
        else if (index == 2) 
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
        else if (index == 3) 
        {
            int i = 0;
            miniOffset[0] = { 5,5 };
            miniOffset[1] = { 45,5 };
            miniOffset[2] = { 5,45 };
            miniOffset[3] = { 45,45 };
            miniOffset[4] = { 25,25 };


            i = MonsterSetPos(pos);

            pos = miniOffset[i] + pos;

            SetName(L"VamIcon");
            SetPos(pos);
            SetScale({ 1.0f, 1.0f });

            mAnimator = new Animator();
            mAnimator->CreateAnimations(L"..\\Resources\\loophero\\monster\\Monster_Icon\\Vampire_Icon", L"Vam_iIdle");
            mAnimator->Play(L"Vam_iIdle", true);
            AddComponent(mAnimator);
        
        }
        else if (index == 4)
        {
            int i = 0;
            miniOffset[0] = { 5,5 };
            miniOffset[1] = { 45,5 };
            miniOffset[2] = { 5,45 };
            miniOffset[3] = { 45,45 };
            miniOffset[4] = { 25,25 };


            i = MonsterSetPos(pos);

            pos = miniOffset[i] + pos;

            SetName(L"DogIcon");
            SetPos(pos);
            SetScale({ 1.0f, 1.0f });

            mAnimator = new Animator();
            mAnimator->CreateAnimations(L"..\\Resources\\loophero\\monster\\Monster_Icon\\Dog_Icon", L"Dog_iIdle");
            mAnimator->Play(L"Dog_iIdle", true);
            AddComponent(mAnimator);

        }
        else if (index == 5)
        {
            int i = 0;
            miniOffset[0] = { 5,5 };
            miniOffset[1] = { 45,5 };
            miniOffset[2] = { 5,45 };
            miniOffset[3] = { 45,45 };
            miniOffset[4] = { 25,25 };


            i = MonsterSetPos(pos);

            pos = miniOffset[i] + pos;

            SetName(L"Skeleton_icon");
            SetPos(pos);
            SetScale({ 1.0f, 1.0f });

            mAnimator = new Animator();
            mAnimator->CreateAnimations(L"..\\Resources\\loophero\\monster\\Monster_Icon\\Skeleton_Icon", L"Skeleton_iIdle");
            mAnimator->Play(L"Skeleton_iIdle", true);
            AddComponent(mAnimator);

        }
     

    }
    MiniIconStore *MiniIconStore::gameObjsStore[11][21][6];

    MiniIconStore::~MiniIconStore()
    {
    }

    void MiniIconStore::Tick()
    {
        GameObject::Tick();

        Vector2 pos = GetPos();

        SetPos(pos);
    }

    void MiniIconStore::Render(HDC hdc)
    {
        GameObject::Render(hdc);
    }

    void MiniIconStore::ClearGameObjs(int y,int x)
    {
        for (int i = 0; i < 6; i++) 
        {
            if (gameObjsStore[y][x][i] != nullptr) 
            {
                gameObjsStore[y][x][i]->Death();
                gameObjsStore[y][x][i] = nullptr;
            }
        }
        WarriorMini::gameSpeedCount = 1;
    }


    int MiniIconStore::MonsterSetPos(Vector2 pos)
    {
        int monsterCount = GameMap::roadTiles[InMapPosCalc(pos).y][InMapPosCalc(pos).x]->GetMonsterCount();



        return monsterCount - 1;
    }

    Vector2 MiniIconStore::InMapPosCalc(Vector2 pos)
    {
        pos.y -= (TILE_SIZE * TILE_SCALE);
        int x = pos.x / (TILE_SIZE * TILE_SCALE);
        int y = pos.y / (TILE_SIZE * TILE_SCALE);

        Vector2 indexPos(x, y);

        return indexPos;
    }

}