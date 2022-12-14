#include "chTitleScene.h"
#include "chSound.h"
#include "chSoundManager.h"
#include "chInput.h"
#include "chSceneManager.h"
#include "chBgImageObject.h"
#include "chObject.h"
#include "LogoAni1.h"
#include "TitleOpmiddle.h"
#include "TitleOpLeft.h"
#include "TitleOpRight.h"
#include "titleStarBtn.h"
#include "chMouseObject.h"
#include "chResources.h"

namespace ch
{
	TitleScene::TitleScene()

	{
		
		
	}
	TitleScene::~TitleScene()
	{
	}
	void TitleScene::Initialize()
	{
		ch::object::Instantiate<MouseObject>(eColliderLayer::Mouse);

		TitleOpmiddle* TitleOp = new TitleOpmiddle();
		TitleOp->SetImage(L"newescmenu_0", L"newescmenu_0.bmp");
		TitleOp->Initialize();

		AddGameObject(TitleOp, eColliderLayer::Tile);

		BgImageObject* bg = new BgImageObject();
		bg->SetImage(L"s_intro_bg_0", L"s_intro_bg_0.bmp");
		bg->Initialize();

		AddGameObject(bg, eColliderLayer::BackGround);


		LogoAni1* Logo1 = new LogoAni1();
		Logo1->SetImage(L"s_game_logo_0", L"s_game_logo_0.bmp");
		Logo1->Initialize();

		AddGameObject(Logo1, eColliderLayer::UI);

		

		TitleOpRight* TitleRight = new TitleOpRight();
		TitleRight->SetImage(L"opt_lang_0", L"opt_lang_0.bmp");
		TitleRight->Initialize();

		AddGameObject(TitleRight, eColliderLayer::Tile);

		TitleOpLeft* TitleLeft = new TitleOpLeft();
		TitleLeft->SetImage(L"opt_font_0", L"opt_font_0.bmp");
		TitleLeft->Initialize();

		AddGameObject(TitleLeft, eColliderLayer::Tile);

		
		
		//chSound->Play(true);
		
		
	}
	void TitleScene::Tick()
	{
		Scene::Tick();

		
	}
	void TitleScene::Render(HDC hdc)
	{


		Scene::Render(hdc);
		wchar_t szFloat[50] = {};
		swprintf_s(szFloat, 50, L"Title Scene");
		int strLen = wcsnlen_s(szFloat, 50);
		TextOut(hdc, 10, 30, szFloat, strLen);
	}
	void TitleScene::Enter()
	{
	}
	void TitleScene::Exit()
	{
	}
}
