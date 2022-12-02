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
#include "chMouseObject.h"


namespace ch
{
	PlayScene::PlayScene()
	{
		CollisionManager::SetLayer(eColliderLayer::Card, eColliderLayer::Mouse, true);

		ch::object::Instantiate<MouseObject>(eColliderLayer::Mouse);

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
		chPlayingCard->SetBGImage(L"Cards01_BG", L"card_rubashka_00.bmp");
		chPlayingCard->SetCardImage(L"Cards01_CARD", L"card_face_11.bmp"); // 산
		chPlayingCard->Initialize();
		chPlayingCard->SetPos({ 0,900 - 145 });
		AddGameObject(chPlayingCard, eColliderLayer::Card);

		PlayingCard* chPlayingCard2 = new PlayingCard();
		chPlayingCard2->SetBGImage(L"Cards02_BG", L"card_rubashka_00.bmp");
		chPlayingCard2->SetCardImage(L"Cards02_CARD", L"card_face_10.bmp"); // 돌
		chPlayingCard2->Initialize();
		chPlayingCard2->SetPos({ 102.5f,900 - 145 });
		AddGameObject(chPlayingCard2, eColliderLayer::Card);

		PlayingCard* chPlayingCard3 = new PlayingCard();
		chPlayingCard3->SetBGImage(L"Cards03_BG", L"card_rubashka_00.bmp");
		chPlayingCard3->SetCardImage(L"Cards03_CARD", L"card_face_6.bmp"); //뱀파이어
		chPlayingCard3->Initialize();
		chPlayingCard3->SetPos({ 205,900 - 145 });
		AddGameObject(chPlayingCard3, eColliderLayer::Card);

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

		GameMap::Instance().Tick();

		if (KEY_DOWN(eKeyCode::N))
		{
			SceneManager::ChangeScene(eSceneType::End);
		}

	}

	void PlayScene::Render(HDC hdc)
	{
		GameMap::Instance().Render(hdc);
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
