#include "GameMap.h"
#include "TileMapObject.h"
#include "chApplication.h"
#include "chInput.h"
#include "chImage.h"
#include "chResources.h"
#include "chObject.h"
#include "TileHeaderFiles.h"
namespace ch 
{
	GameMap GameMap::inst;
	GameMap::GameMap()
	{

		//s_lands_11.bmp
		//mTilesImage = Resources::Load<Image>(L"Monster", L"..\\Resources\\Image\\Tile\\s_lands_11.bmp");

		// 배열 초기화
		mTiles.resize(11);
		for (size_t i = 0; i < 11; i++)
		{
			mTiles[i].resize(21);
		}

		/*
		for (int i = 0; i < 11; i++)
		{
			for (int j = 0; j < 21; j++)
			{
				
			}
		}
		*/
	
	}

	GameMap::~GameMap()
	{
	}
	void GameMap::Initialize()
	{
		Map1Create();
		


	}
	void GameMap::Tick()
	{
		//맵 배열의 숫자 
		
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


			if (y >= 0 && y < 11 && x >= 0 && x < 21)
			{
				if (mTileType == 1)
				{
					if (mTiles[y][x] == nullptr)
					{
						//TileMapObject* gameObj = ch::object::Instantiate<StoneMountain>(objectPos, eColliderLayer::Tile); //산
						TileMapObject* gameObj = ch::object::Instantiate<newroad_2>(MapPosCalc(y, x), eColliderLayer::Tile); //테스트
						gameObj->SetTileType(1);
						mTiles[y][x] = gameObj;
					}
				}
				else if (mTileType == 2)
				{
					if (mTiles[y][x] == nullptr)
					{
						TileMapObject* gameObj = ch::object::Instantiate<Rock>(objectPos, eColliderLayer::Tile); //바위
						gameObj->SetTileType(2);
						mTiles[y][x] = gameObj;
					}
				}
				else if (mTileType == 3)
				{

					if (mTiles[y][x] == nullptr)
					{
						TileMapObject* gameObj = ch::object::Instantiate<Vampire_Mansion>(objectPos, eColliderLayer::Tile); // 뱀파이어집
						gameObj->SetTileType(3);
						mTiles[y][x] = gameObj;
					}
				}
				else if (mTileType == 4)
				{
					if (mTiles[y][x] == nullptr)
					{
						TileMapObject* gameObj = ch::object::Instantiate<SpiderCocoon>(objectPos, eColliderLayer::Tile); // 거미고치
						gameObj->SetTileType(4);
						mTiles[y][x] = gameObj;
					}
				}
				else if (mTileType == 5)//제거 카드
				{
					if (mTiles[y][x] != nullptr)
					{
						mTiles[y][x]->Death();
						mTiles[y][x] = nullptr;
					}
				}
				else if (mTileType == 6)
				{
					if (mTiles[y][x] == nullptr)
					{
						TileMapObject* gameObj = ch::object::Instantiate<Vilage>(objectPos, eColliderLayer::Tile); // 마을
						gameObj->SetTileType(6);
						mTiles[y][x] = gameObj;

					}
				}
				else if (mTileType == 7)
				{
					if (mTiles[y][x] == nullptr)
					{
						TileMapObject* gameObj = ch::object::Instantiate<Grove>(objectPos, eColliderLayer::Tile); // 숲
						gameObj->SetTileType(7);
						mTiles[y][x] = gameObj;
					}
				}
				else if (mTileType == 8)
				{
					if (mTiles[y][x] == nullptr)
					{
						TileMapObject* gameObj = ch::object::Instantiate<Cemetery>(objectPos, eColliderLayer::Tile); // 무덤
						gameObj->SetTileType(8);
						mTiles[y][x] = gameObj;
					}
				}

				else if (mTileType == 9)
				{
					if (mTiles[y][x] == nullptr)
					{
						TileMapObject* gameObj = ch::object::Instantiate<Coffers>(objectPos, eColliderLayer::Tile); // 금고
						gameObj->SetTileType(9);
						mTiles[y][x] = gameObj;
					}
				}

				else if (mTileType == 10)
				{
					if (mTiles[y][x] == nullptr)
					{
						if (mTiles[y - 1][x]->GetTileType() == 6 || mTiles[y + 1][x]->GetTileType() == 6 || mTiles[y][x - 1]->GetTileType() == 6 || mTiles[y][x + 1]->GetTileType() == 6)
						{
							TileMapObject* gameObj = ch::object::Instantiate<Wheat>(objectPos, eColliderLayer::Tile); // 밀밭
							gameObj->SetTileType(10);
							mTiles[y][x] = gameObj;

						}
					
					}
				}
			}


			if(checkTileType >= 1.0f)
			{
				for (int i = 0; i < 11; i++)
				{
					for (int j = 0; j < 21; j++)
					{
						mTiles[i][j]->GetTileType();
					}
				}
				checkTileType = 0;
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

	Vector2 GameMap::MapPosCalc(int y, int x)
	{

		Vector2 indexPos(x, y);
		indexPos.x = x * (TILE_SIZE * TILE_SCALE);
		indexPos.y = y * (TILE_SIZE * TILE_SCALE);
		indexPos.y += (TILE_SIZE * TILE_SCALE);

		Vector2 objectPos = indexPos;

		return objectPos;
	}

	void GameMap::Map1Create()
	{
		
		TileMapObject* gameObj = ch::object::Instantiate<newroad_2>(MapPosCalc(3, 6), eColliderLayer::Tile); //2번 길
		gameObj->SetTileType(99);
		mTiles[3][6] = gameObj;
		
		gameObj = ch::object::Instantiate<newroad_0>(MapPosCalc(3, 7), eColliderLayer::Tile); //가로 길
		gameObj->SetTileType(99);
		mTiles[3][7] = gameObj;

		gameObj = ch::object::Instantiate<newroad_0>(MapPosCalc(3, 8), eColliderLayer::Tile); //가로 길
		gameObj->SetTileType(99);
		mTiles[3][8] = gameObj;

		gameObj = ch::object::Instantiate<newroad_0>(MapPosCalc(3, 9), eColliderLayer::Tile); //가로 길
		gameObj->SetTileType(99);
		mTiles[3][9] = gameObj;

		gameObj = ch::object::Instantiate<newroad_0>(MapPosCalc(3, 10), eColliderLayer::Tile); //가로 길
		gameObj->SetTileType(99);
		mTiles[3][10] = gameObj;

		gameObj = ch::object::Instantiate<newroad_0>(MapPosCalc(3, 11), eColliderLayer::Tile); //가로 길
		gameObj->SetTileType(99);
		mTiles[3][11] = gameObj;
		
		gameObj = ch::object::Instantiate<newroad_3>(MapPosCalc(3, 12), eColliderLayer::Tile); //3번 길
		gameObj->SetTileType(99);
		mTiles[3][12] = gameObj;

		gameObj = ch::object::Instantiate<newroad_4>(MapPosCalc(4,12), eColliderLayer::Tile); //4번 길
		gameObj->SetTileType(99);
		mTiles[4][12] = gameObj;

		gameObj = ch::object::Instantiate<newroad_0>(MapPosCalc(4, 13), eColliderLayer::Tile); //가로 길
		gameObj->SetTileType(99);
		mTiles[4][13] = gameObj;

		gameObj = ch::object::Instantiate<newroad_0>(MapPosCalc(4, 14), eColliderLayer::Tile); //가로 길
		gameObj->SetTileType(99);
		mTiles[4][14] = gameObj;

		gameObj = ch::object::Instantiate<newroad_0>(MapPosCalc(4, 15), eColliderLayer::Tile); //가로 길
		gameObj->SetTileType(99);
		mTiles[4][15] = gameObj;

		gameObj = ch::object::Instantiate<newroad_3>(MapPosCalc(4, 16), eColliderLayer::Tile); //3번 길
		gameObj->SetTileType(99);
		mTiles[4][16] = gameObj;

		gameObj = ch::object::Instantiate<newroad_1>(MapPosCalc(5,16), eColliderLayer::Tile); //세로 길
		gameObj->SetTileType(99);
		mTiles[5][16] = gameObj;

		gameObj = ch::object::Instantiate<newroad_1>(MapPosCalc(6, 16), eColliderLayer::Tile); //세로 길
		gameObj->SetTileType(99);
		mTiles[6][16] = gameObj;

		gameObj = ch::object::Instantiate<newroad_1>(MapPosCalc(7, 16), eColliderLayer::Tile); //세로 길
		gameObj->SetTileType(99);
		mTiles[7][16] = gameObj;

		gameObj = ch::object::Instantiate<newroad_5>(MapPosCalc(8, 16), eColliderLayer::Tile); //5번길
		gameObj->SetTileType(99);
		mTiles[8][16] = gameObj;

		gameObj = ch::object::Instantiate<newroad_0>(MapPosCalc(8, 15), eColliderLayer::Tile); //가로 길
		gameObj->SetTileType(99);
		mTiles[8][15] = gameObj;


	}

	

}

/*
		TileMapObject* gameObj = ch::object::Instantiate<newroad_0>(MapPosCalc( , ), eColliderLayer::Tile); //가로 길
		gameObj->SetTileType(99);
		mTiles[y][x] = gameObj;

		TileMapObject* gameObj = ch::object::Instantiate<newroad_1>(MapPosCalc( , ), eColliderLayer::Tile); //세로 길
		gameObj->SetTileType(99);
		mTiles[y][x] = gameObj;

		TileMapObject* gameObj = ch::object::Instantiate<newroad_2>(MapPosCalc( , ), eColliderLayer::Tile); //2번 길
		gameObj->SetTileType(99);
		mTiles[y][x] = gameObj;

		TileMapObject* gameObj = ch::object::Instantiate<newroad_3>(MapPosCalc( , ), eColliderLayer::Tile); //3번 길
		gameObj->SetTileType(99);
		mTiles[y][x] = gameObj;

		TileMapObject* gameObj = ch::object::Instantiate<newroad_4>(MapPosCalc( , ), eColliderLayer::Tile); //4번 길
		gameObj->SetTileType(99);
		mTiles[y][x] = gameObj;

		TileMapObject* gameObj = ch::object::Instantiate<newroad_5>(MapPosCalc( , ), eColliderLayer::Tile); //5번길
		gameObj->SetTileType(99);
		mTiles[y][x] = gameObj;
		*/