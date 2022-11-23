#include "chTitleScene.h"
#include "chInput.h"
#include "chSceneManager.h"
#include "chBgImageObject.h"
#include "chObject.h"
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
		BgImageObject* bg = new BgImageObject();
		bg->SetImage(L"s_intro_bg_0", L"s_intro_bg_0.bmp");
		bg->Initialize();

		AddGameObject(bg, eColliderLayer::BackGround);
	}
	void TitleScene::Tick()
	{
		Scene::Tick();

		if (KEY_DOWN(eKeyCode::N))
		{
			SceneManager::ChangeScene(eSceneType::Play);
		}
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
