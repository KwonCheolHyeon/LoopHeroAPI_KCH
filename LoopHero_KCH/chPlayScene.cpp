#include "chPlayScene.h"
#include "chPlayer.h"
#include "chInput.h"
#include "chSceneManager.h"
#include "FightPageOBJ.h"
#include "chCollisionManager.h"
#include "chObject.h"
#include "EquipmentPage.h"
#include "chDayOBJ.h"
#include "chSpeedPanelOBJ.h"
#include "chPlashkaOBJ.h"
#include "chItemPanelOBJ.h"
#include "PlayingCard.h"
#include "chApplication.h"
#include "GameMap.h"


namespace ch
{
	PlayScene::PlayScene()
	{
		ch::object::Instantiate<GameMap>(eColliderLayer::Greed);


		chDayOBJ* day = new chDayOBJ();
		day->SetImage(L"DayPanel", L"day_0.bmp");
		day->Initialize();
		AddGameObject(day, eColliderLayer::BackGround);

		chSpeedPanelOBJ* speedPanel = new chSpeedPanelOBJ();
		speedPanel->SetImage(L"SpeedPanel", L"s_speedpanel_0.bmp");
		speedPanel->Initialize();
		AddGameObject(speedPanel, eColliderLayer::BackGround);


		chPlashkaOBJ* chPlashka = new chPlashkaOBJ();
		chPlashka->SetImage(L"chPlashka", L"plashka_0.bmp");
		chPlashka->Initialize();
		AddGameObject(chPlashka, eColliderLayer::BackGround);

		chItemPanelOBJ* chItemPanel = new chItemPanelOBJ();
		chItemPanel->SetImage(L"chItemPanel", L"travelitempanel_0.bmp");
		chItemPanel->Initialize();
		AddGameObject(chItemPanel, eColliderLayer::BackGround);

		
		PlayingCard* chPlayingCard = new PlayingCard();
		chPlayingCard->SetImage(L"Cards", L"s_card_rubashka_3.bmp");
		chPlayingCard->Initialize();
		chPlayingCard->SetPos({ 1600 - 150,0 });
		AddGameObject(chPlayingCard, eColliderLayer::BackGround);
		


		EquipmentPage* ep = new EquipmentPage();
		ep->SetImage(L"EquipmentPage", L"s_hud_24_3.bmp");
		ep->Initialize();

		AddGameObject(ep, eColliderLayer::BackGround);
	}

	PlayScene::~PlayScene()
	{

	}

	void PlayScene::Initialize()
	{
		
		/*
		FightPageOBJ* fpg = new FightPageOBJ();
		fpg->SetImage(L"FightPage", L"s_fight_window_0.bmp");
		fpg->Initialize();

		AddGameObject(fpg, eColliderLayer::BackGround);
		*/
		
	}

	void PlayScene::Tick()
	{
		
		Scene::Tick();

		if (KEY_DOWN(eKeyCode::N))
		{
			SceneManager::ChangeScene(eSceneType::End);
		}

	}

	void PlayScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
		
		WindowData mainWidnow = Application::GetInstance().GetWindowData();		
	}

	void PlayScene::Enter()
	{

	}

	void PlayScene::Exit()
	{

	}
}
