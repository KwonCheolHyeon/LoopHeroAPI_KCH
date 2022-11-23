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

namespace ch
{
	PlayScene::PlayScene()
	{
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

		/*
		PlayingCard* chPlayingCard = new PlayingCard();
		chPlayingCard->SetImage(L"Cards", L"s_card_rubashka_3.bmp");
		chPlayingCard->Initialize();
		chPlayingCard->SetPos({ 1600 - 150,0 });
		AddGameObject(chPlayingCard, eColliderLayer::BackGround);
		*/


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
		
		
		WindowData mainWidnow = Application::GetInstance().GetWindowData();

		HPEN redPen = CreatePen(PS_SOLID, 1, RGB(0, 125, 0));
		HPEN oldPen = (HPEN)SelectObject(hdc, redPen);

		int maxRow = mainWidnow.height / TILE_SIZE * TILE_SCALE ;
		for (size_t i = 0; i < maxRow; i++)
		{
			MoveToEx(hdc, 0, TILE_SIZE * i * TILE_SCALE, nullptr);
			LineTo(hdc, mainWidnow.width, TILE_SIZE * i * TILE_SCALE);
		}

		int maxColumn = mainWidnow.width / TILE_SIZE * TILE_SCALE ;
		for (size_t i = 0; i < maxColumn; i++)
		{
			MoveToEx(hdc, TILE_SIZE * i * TILE_SCALE, 0, nullptr);
			LineTo(hdc, TILE_SIZE * i * TILE_SCALE, mainWidnow.height);
		}

		(HPEN)SelectObject(hdc, oldPen);
		DeleteObject(redPen);


		Scene::Render(hdc);
		
	}

	void PlayScene::Enter()
	{

	}

	void PlayScene::Exit()
	{

	}
}
