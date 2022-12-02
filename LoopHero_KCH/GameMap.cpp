#include "GameMap.h"
#include "chApplication.h"
#include "chInput.h"
#include "chImage.h"
#include "chResources.h"
#include "chObject.h"
#include "chStoneMountain.h"
#include "newroad_0.h"
#include "Cemetery.h"
#include "chRock.h"

namespace ch 
{
	GameMap::GameMap()
	{
		//s_lands_11.bmp
		//mTilesImage = Resources::Load<Image>(L"Monster", L"..\\Resources\\Image\\Tile\\s_lands_11.bmp");

		// 배열 초기화
		mTiles.resize(12);
		for (size_t i = 0; i < 12; i++)
		{

			mTiles[i].resize(21);
		}
	}
	GameMap::~GameMap()
	{
	}
	void GameMap::Initialize()
	{

	}
	void GameMap::Tick()
	{
		if (KEY_DOWN(eKeyCode::LBTN))
		{
			Vector2  mousePos = Input::GetMousePos();

			int y = (mousePos.y - (TILE_SIZE * TILE_SCALE)) / (TILE_SIZE * TILE_SCALE);
			int x = mousePos.x / (TILE_SIZE * TILE_SCALE);

			Vector2 indexPos(x, y);
			indexPos.x = x * (TILE_SIZE * TILE_SCALE);
			indexPos.y = y * (TILE_SIZE * TILE_SCALE);
			indexPos.y += (TILE_SIZE * TILE_SCALE);
			//int index = (y * TILE_LINE_X) + (x % TILE_LINE_X);
			Vector2 objectPos = indexPos;

			if (y >= 0 && y < 12 && x >= 0 && x < 21)
			{
				TileMapObject* gameObj
					= ch::object::Instantiate<newroad_0>(objectPos, eColliderLayer::Tile);

				mTiles[y][x] = gameObj;
			}
		}
	}
	void GameMap::Render(HDC hdc)
	{
		WindowData mainWidnow = Application::GetInstance().GetWindowData();
		HPEN redPen = CreatePen(PS_SOLID, 1, RGB(0, 125, 0));
		HPEN oldPen = (HPEN)SelectObject(hdc, redPen);

		int maxRow = mainWidnow.height / TILE_SIZE * TILE_SCALE;
		for (size_t i = 0; i < 13; i++)
		{
			MoveToEx(hdc, 0, TILE_SIZE * i * TILE_SCALE, nullptr);
			LineTo(hdc, mainWidnow.width, TILE_SIZE * i * TILE_SCALE);
		}

		int maxColumn = mainWidnow.width / TILE_SIZE * TILE_SCALE;

		for (size_t i = 0; i < 22; i++)
		{
			MoveToEx(hdc, TILE_SIZE * i * TILE_SCALE, 62.5f, nullptr);
			LineTo(hdc, TILE_SIZE * i * TILE_SCALE, mainWidnow.height);
		}

		(HPEN)SelectObject(hdc, oldPen);
		DeleteObject(redPen);
	}


}