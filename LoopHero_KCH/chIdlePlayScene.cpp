#include "chIdlePlayScene.h"
#include "framework.h"
#include "LoopHero_KCH.h"
//#include "chToolScene.h"
#include "chApplication.h"
#include "chSceneManager.h"
#include "chScene.h"
//#include "chTilePalette.h"
#include "chImage.h"
#include "chInput.h"


namespace ch
{

	chIdlePlayScene::chIdlePlayScene()
	{
	}

	chIdlePlayScene::~chIdlePlayScene()
	{
	}

	void chIdlePlayScene::Initialize()
	{
	}

	void chIdlePlayScene::Tick()
	{
		Scene::Tick();

		if (KEY_DOWN(eKeyCode::N))
		{
			SceneManager::ChangeScene(eSceneType::End);
		}
	}

	void chIdlePlayScene::Render(HDC hdc)
	{
		Scene::Render(hdc);

		WindowData mainWidnow = Application::GetInstance().GetWindowData();

		HPEN redPen = CreatePen(PS_SOLID, 2, RGB(0, 125, 0));
		HPEN oldPen = (HPEN)SelectObject(hdc, redPen);

		int maxRow = mainWidnow.height / TILE_SIZE * TILE_SCALE + 1;
		for (size_t i = 0; i < maxRow; i++)
		{
			MoveToEx(hdc, 0, TILE_SIZE * i * TILE_SCALE, nullptr);
			LineTo(hdc, mainWidnow.width, TILE_SIZE * i * TILE_SCALE);
		}

		int maxColumn = mainWidnow.width / TILE_SIZE * TILE_SCALE + 1;
		for (size_t i = 0; i < maxColumn; i++)
		{
			MoveToEx(hdc, TILE_SIZE * i * TILE_SCALE, 0, nullptr);
			LineTo(hdc, TILE_SIZE * i * TILE_SCALE, mainWidnow.height);
		}

		(HPEN)SelectObject(hdc, oldPen);
		DeleteObject(redPen);
		
	}

	void chIdlePlayScene::Enter()
	{
	}

	void chIdlePlayScene::Exit()
	{
	}

}