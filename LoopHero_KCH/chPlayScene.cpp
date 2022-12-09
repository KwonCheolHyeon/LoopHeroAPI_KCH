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

		GameMap::Instance().Initialize();

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

		
		PlayingCard* chPlayingCard = new PlayingCard(1);
		chPlayingCard->SetBGImage(L"Cards01_BG", L"card_rubashka_00.bmp");
		chPlayingCard->SetCardImage(L"Cards01_CARD", L"card_face_11.bmp"); // 산
		chPlayingCard->Initialize();
		chPlayingCard->SetPos({ 0,900 - 145 });
		AddGameObject(chPlayingCard, eColliderLayer::Card);

		PlayingCard* chPlayingCard2 = new PlayingCard(2);
		chPlayingCard2->SetBGImage(L"Cards02_BG", L"card_rubashka_00.bmp");
		chPlayingCard2->SetCardImage(L"Cards02_CARD", L"card_face_10.bmp"); // 돌
		chPlayingCard2->Initialize();
		chPlayingCard2->SetPos({ 102.5f,900 - 145 });
		AddGameObject(chPlayingCard2, eColliderLayer::Card);

		PlayingCard* chPlayingCard3 = new PlayingCard(3);
		chPlayingCard3->SetBGImage(L"Cards03_BG", L"card_rubashka_00.bmp");
		chPlayingCard3->SetCardImage(L"Cards03_CARD", L"card_face_6.bmp"); //뱀파이어
		chPlayingCard3->Initialize();
		chPlayingCard3->SetPos({ 205,900 - 145 });
		AddGameObject(chPlayingCard3, eColliderLayer::Card);

		PlayingCard* chPlayingCard4 = new PlayingCard(4);
		chPlayingCard4->SetBGImage(L"Cards03_BG", L"card_rubashka_00.bmp");
		chPlayingCard4->SetCardImage(L"Cards04_CARD", L"card_face_5.bmp"); //거미
		chPlayingCard4->Initialize();
		chPlayingCard4->SetPos({ 307.5f,900 - 145 });
		AddGameObject(chPlayingCard4, eColliderLayer::Card);

		PlayingCard* chPlayingCard5 = new PlayingCard(5);
		chPlayingCard5->SetBGImage(L"Cards03_BG", L"card_rubashka_00.bmp");
		chPlayingCard5->SetCardImage(L"Cards05_CARD", L"card_face_0.bmp"); //제거 카드
		chPlayingCard5->Initialize();
		chPlayingCard5->SetPos({ 410,900 - 145 });
		AddGameObject(chPlayingCard5, eColliderLayer::Card);

		PlayingCard* chPlayingCard6 = new PlayingCard(6);
		chPlayingCard6->SetBGImage(L"Cards03_BG", L"card_rubashka_00.bmp");
		chPlayingCard6->SetCardImage(L"Cards06_CARD", L"card_face_2.bmp"); //마을 카드
		chPlayingCard6->Initialize();
		chPlayingCard6->SetPos({ 512.5f,900 - 145 });
		AddGameObject(chPlayingCard6, eColliderLayer::Card);

		PlayingCard* chPlayingCard7 = new PlayingCard(7);
		chPlayingCard7->SetBGImage(L"Cards03_BG", L"card_rubashka_00.bmp");
		chPlayingCard7->SetCardImage(L"Cards07_CARD", L"card_face_3.bmp"); //숲 카드
		chPlayingCard7->Initialize();
		chPlayingCard7->SetPos({ 615,900 - 145 });
		AddGameObject(chPlayingCard7, eColliderLayer::Card);

		PlayingCard* chPlayingCard8 = new PlayingCard(8);
		chPlayingCard8->SetBGImage(L"Cards03_BG", L"card_rubashka_00.bmp");
		chPlayingCard8->SetCardImage(L"Cards08_CARD", L"card_face_1.bmp"); //무덤 카드
		chPlayingCard8->Initialize();
		chPlayingCard8->SetPos({ 717.5f,900 - 145 });
		AddGameObject(chPlayingCard8, eColliderLayer::Card);

		PlayingCard* chPlayingCard9 = new PlayingCard(9);
		chPlayingCard9->SetBGImage(L"Cards03_BG", L"card_rubashka_00.bmp");
		chPlayingCard9->SetCardImage(L"Cards09_CARD", L"card_face_45.bmp"); //금고 카드
		chPlayingCard9->Initialize();
		chPlayingCard9->SetPos({ 820,900 - 145 });
		AddGameObject(chPlayingCard9, eColliderLayer::Card);

		PlayingCard* chPlayingCard10 = new PlayingCard(10);
		chPlayingCard10->SetBGImage(L"Cards03_BG", L"card_rubashka_00.bmp");
		chPlayingCard10->SetCardImage(L"Cards10_CARD", L"card_face_4.bmp"); //밀밭 카드
		chPlayingCard10->Initialize();
		chPlayingCard10->SetPos({ 922.5f,900 - 145 });
		AddGameObject(chPlayingCard10, eColliderLayer::Card);



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
