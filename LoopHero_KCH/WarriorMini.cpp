#include "WarriorMini.h"
#include "chSceneManager.h"
#include "chInput.h"
#include "chScene.h"
#include "chImage.h"
#include "chResources.h"
#include "GameMap.h"
#include "chAnimator.h"
#include "chObject.h"
#include "chTime.h"
#include "TileMapObject.h"
#include "FightPageOBJ.h"
#include "chUiManager.h"
#include "LoopWarrior.h"
#include "chMiniIconStore.h"
#include "chItemBG.h"
#include "chSound.h"
#include "chSoundManager.h"


namespace ch 
{
    WarriorMini::WarriorMini()
    {
        SetName(L"WarriorMini");
        SetPos({ 1600 / 2, 300 / 2 });
        SetScale({ 3.0f, 3.0f });
        

        if (mImage == nullptr)
        {
            mImage = Resources::Load<Image>(L"Warrior", L"..\\Resources\\loophero\\character\\warrior\\warrior_00.bmp");
        }

        mAnimator = new Animator();
        mAnimator->CreateAnimations(L"..\\Resources\\loophero\\character\\Warrior_Icon", L"Warrior_Idle");
        mAnimator->Play(L"Warrior_Idle", true);
        AddComponent(mAnimator);
    }
    
    WarriorMini::WarriorMini(Vector2 pos)
    {
        distanceOne = 0.0f;
        gameSpeed = 0;
        gameSpeedCount = 1;
        pos = miniOffset + pos;
        boosOneCheck = true;
        bgmOneCheck = true;
        SetName(L"WarriorMini");
        SetPos(pos);
        SetScale({ 3.0f, 3.0f });

        if (mImage == nullptr)
        {
            mImage = Resources::Load<Image>(L"Warrior", L"..\\Resources\\loophero\\character\\warrior\\warrior_00.bmp");
        }

        mAnimator = new Animator();
        mAnimator->CreateAnimations(L"..\\Resources\\loophero\\character\\Player_Icon", L"Warrior_Idle");
        mAnimator->Play(L"Warrior_Idle", true);
        AddComponent(mAnimator);

      
        for (int i = 0; i < 11; i++) 
        {
            for (int j = 0; j < 21; j++) 
            {
                if (roadTilesCopy[i][j]->GetTileType() == 100) 
                {
                    pY = i;
                    pX = j;
                }
            }
        }

        pIndex = Vector2(pX,pY);
        Pdir = dirSelect(pIndex.x,pIndex.y);
        Loop = 1;
        ch::object::Instantiate<ItemBG>(0, 0, 0, (eColliderLayer::Card));
        ch::object::Instantiate<ItemBG>(0, 1, 0, (eColliderLayer::Card));
        ch::object::Instantiate<ItemBG>(0, 2, 0, (eColliderLayer::Card));
        ch::object::Instantiate<ItemBG>(0, 3, 0, (eColliderLayer::Card));

        miniHP = 1000;
        miniNowHp = miniHP;

        gameStart_bgm = Resources::Load<Sound>(L"stageStart", L"..\\Resources\\sound\\bgm\\snd_music1_2.wav");
        lichPotal_bgm = Resources::Load<Sound>(L"LichPotal", L"..\\Resources\\sound\\lich\\snd_mus_Lich_portal.wav");
        Walk_Bgm = Resources::Load<Sound>(L"heroWalk", L"..\\Resources\\sound\\effect\\snd_hero_steps.wav"); //
        campfire_bgm = Resources::Load<Sound>(L"campFire", L"..\\Resources\\sound\\effect\\snd_campfire_heal.wav");//??????????
        daySound = Resources::Load<Sound>(L"daySound", L"..\\Resources\\sound\\effect\\snd_start_new_day.wav");
        battleStart_sound = Resources::Load<Sound>(L"battleStart", L"..\\Resources\\sound\\effect\\snd_battle_start.wav");
        Time::gameSpeed = 1;
    }
    int WarriorMini::Loop;
    int WarriorMini::gameSpeedCount;
    int WarriorMini::miniHP;
    int WarriorMini::miniNowHp;

    WarriorMini::~WarriorMini()
    {

    }

    void WarriorMini::Tick()
    {
        gameSpeed = (25 * Time::DeltaTime() * gameSpeedCount);

        GameObject::Tick();

        Vector2 pos = GetPos();

        if (distanceOne >= TILE_SIZE * TILE_SCALE)
        {

            distanceOne = 0;
            Pdir=dirSelect(pIndex.x,pIndex.y);
            if (GameMap::roadTiles[prevPY][prevPX]->GetMonsterCount() > 0) //???????? ??????? ????
            {//??????
               
               gameSpeedCount = 0;
               battleStart_sound->Play(false);
               FightPageOBJ* fpg = new FightPageOBJ(prevPY, prevPX);
               fpg->SetImage(L"FightPage", L"s_fight_window_0.bmp");
               fpg->Initialize();
               Time::gameSpeed = 0;
               SceneManager::GetPlayScene()->AddGameObject(fpg, eColliderLayer::BackGroundOBJ);
               fpg2 = fpg;

            }
            if(GameMap::roadTiles[prevPY][prevPX]->GetTileType() == 100)
            {
                if (GameMap::roadTiles[prevPY][prevPX]->GetMonsterType(0) ==  6) //????
                {
                    lichPotal_bgm->Stop(true);
                    
                }
                campfire_bgm->Play(false);
                miniNowHp += 500;
                Loop += 1;

            }

         
            if (miniNowHp > miniHP) 
            {
                miniNowHp = miniHP;
            }

        }

        if (bgmOneCheck) 
        {
            bgmOneCheck = false;
            gameStart_bgm->Play(true);
        }

        if (GameMap::roadTiles[7][12]->GetMonsterType(0) == 6 && boosOneCheck== true) //????
        {
            boosOneCheck = false;
            gameStart_bgm->Stop(true);
            lichPotal_bgm->Play(true);
        }
        if (KEY_DOWN(eKeyCode::Q))
        {
            LoopWarrior::FightDone = true;
        }

        if (LoopWarrior::FightDone == true) 
        {
            LoopWarrior::FightDone == false;
            
            GameMap::roadTiles[prevPY][prevPX]->clearMonsters();
            MiniIconStore::ClearGameObjs(prevPY, prevPX);
            FightPageOBJ::objDeath();
            fpg2->Death();
           
            Time::gameSpeed = 1;
        }

       
       
        if (Time::mDays == 1)
        {
            daySound->Play(false);
        }

       


        moveTo(Pdir, pos);

        distanceOne += gameSpeed;//???????? ????


    }
    void WarriorMini::Render(HDC hdc)
    {
        GameObject::Render(hdc);
    }
  
 
    void WarriorMini::moveTo(int dir, Vector2 pos)
    {
        if (dir == 1) //??????
        {
            pos.x += gameSpeed;
        }
        else if(dir == 2)//????
        {
            pos.y -= gameSpeed;
        }
        else if (dir == 3)//??????
        {
            pos.x -= gameSpeed;
        }
        else if (dir == 4)
        {
            pos.y += gameSpeed;
        }

        SetPos(pos);
    }

    int WarriorMini::dirSelect(int pX,int pY) 
    {

        if (roadTilesCopy[pY][pX+1]->GetMapBaseCode() == 99 && prevPX != pX+1)//??????
        {
            prevPX = pX;
            prevPY = pY;
            
            pX = pX + 1;
            pIndex.x = pX;
            pIndex.y = pY;
            return 1;
        }
        else if (roadTilesCopy[pY-1][pX]->GetMapBaseCode() == 99 && prevPY != pY-1) //????
        {
            prevPX = pX;
            prevPY = pY;

            pY = pY-1;
            pIndex.x = pX;
            pIndex.y = pY;
            return 2;
        }
        else if (roadTilesCopy[pY][pX-1]->GetMapBaseCode() == 99 && prevPX != pX-1 )//????
        {
            prevPX = pX;
            prevPY = pY;

            pX = pX - 1;
            pIndex.x = pX;
            pIndex.y = pY;
            return 3;
        }
        else if (roadTilesCopy[pY+1][pX]->GetMapBaseCode() == 99 && prevPY != pY+1)//????
        {
            prevPX = pX;
            prevPY = pY;

            pY = pY + 1;
            pIndex.x = pX;
            pIndex.y = pY;
            return 4;
        }
    
    }


    bool WarriorMini::fullItemCheck()
    {
        int count = 0;

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (ItemBG::bagChecks[i][j] != nullptr)
                {
                    count++;
                }             
            }
        }

        if (count >= 12)
        {
            return false;
        }
        else if (count < 12)
        {
            return true;
        }
    }
}