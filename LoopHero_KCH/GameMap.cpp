#include "GameMap.h"
#include "TileMapObject.h"
#include "chApplication.h"
#include "chInput.h"
#include "chImage.h"
#include "chResources.h"
#include "chObject.h"
#include "chTime.h"
#include "TileHeaderFiles.h"
namespace ch 
{

	GameMap GameMap::inst;
	GameMap::GameMap()
	{
		// �迭 �ʱ�ȭ
		mTiles.resize(11);
		for (size_t i = 0; i < 11; i++)
		{
			mTiles[i].resize(21);
		}
		
	}

	GameMap::~GameMap()
	{

	}
	void GameMap::Initialize()
	{
		initMap();//�ʱ�ȭ
		aroundRoad();
	}

	void GameMap::Tick()
	{
		//�ð� üũ
		//checkTileType += Time::DeltaTime();

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
					if (mTiles[y][x]->GetTileType() == 0)
					{
						TileMapObject* gameObj = ch::object::Instantiate<StoneMountain>(objectPos, eColliderLayer::Tile); //��
						gameObj->SetTileType(1);
						mTiles[y][x] = gameObj;

					}
				}
				else if (mTileType == 2)
				{
					if (mTiles[y][x]->GetTileType() == 0)
					{
						TileMapObject* gameObj = ch::object::Instantiate<Rock>(objectPos, eColliderLayer::Tile); //����
						gameObj->SetTileType(2);
						mTiles[y][x] = gameObj;
					}
				}
				
				else if (mTileType == 3)
				{

					if (mTiles[y][x] == nullptr)
					{
						TileMapObject* gameObj = ch::object::Instantiate<Vampire_Mansion>(objectPos, eColliderLayer::Tile); // �����̾���
						gameObj->SetTileType(3);
						mTiles[y][x] = gameObj;
					}
				}
				else if (mTileType == 4)
				{
					if (mTiles[y][x] == nullptr)
					{
						TileMapObject* gameObj = ch::object::Instantiate<SpiderCocoon>(objectPos, eColliderLayer::Tile); // �Ź̰�ġ
						gameObj->SetTileType(4);
						mTiles[y][x] = gameObj;
					}
				}
				else if (mTileType == 5)//���� ī��
				{
					if (mTiles[y][x] != nullptr) {
						if (mTiles[y][x]->GetTileType() != 99)
						{
							mTiles[y][x]->Death();
							TileMapObject* gameObj = ch::object::Instantiate<BasePlace>(MapPosCalc(y, x), eColliderLayer::BackGround); // ����
							gameObj->SetTileType(0);
							mTiles[y][x] = gameObj;
						}
					}
				}
				else if (mTileType == 6)
				{
					if (mTiles[y][x] == nullptr)
					{
						TileMapObject* gameObj = ch::object::Instantiate<Vilage>(objectPos, eColliderLayer::Tile); // ����
						gameObj->SetTileType(6);
						mTiles[y][x] = gameObj;

					}
				}
				else if (mTileType == 7)
				{
					if (mTiles[y][x] == nullptr)
					{
						TileMapObject* gameObj = ch::object::Instantiate<Grove>(objectPos, eColliderLayer::Tile); // ��
						gameObj->SetTileType(7);
						mTiles[y][x] = gameObj;
					}
				}
				else if (mTileType == 8)
				{
					if (mTiles[y][x] == nullptr)
					{
						TileMapObject* gameObj = ch::object::Instantiate<Cemetery>(objectPos, eColliderLayer::Tile); // ����
						gameObj->SetTileType(8);
						mTiles[y][x] = gameObj;
					}
				}
				else if (mTileType == 9)
				{
					if (mTiles[y][x] == nullptr)
					{
						TileMapObject* gameObj = ch::object::Instantiate<Coffers>(objectPos, eColliderLayer::Tile); // �ݰ�
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
							TileMapObject* gameObj = ch::object::Instantiate<Wheat>(objectPos, eColliderLayer::Tile); // �й�
							gameObj->SetTileType(10);
							mTiles[y][x] = gameObj;

						}
					}
				}


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
		
		TileMapObject* gameObj = ch::object::Instantiate<newroad_2>(MapPosCalc(3, 6), eColliderLayer::Tile); //2�� ��
		gameObj->SetTileType(0);
		gameObj->SetTileBase(0);
		gameObj->SetMapBaseCode(99);
		mTiles[3][6] = gameObj;
		
		gameObj = ch::object::Instantiate<newroad_0>(MapPosCalc(3, 7), eColliderLayer::Tile); //���� ��
		gameObj->SetTileType(0);
		gameObj->SetTileBase(0);
		gameObj->SetMapBaseCode(99);
		mTiles[3][7] = gameObj;

		gameObj = ch::object::Instantiate<newroad_0>(MapPosCalc(3, 8), eColliderLayer::Tile); //���� ��
		gameObj->SetTileType(0);
		gameObj->SetTileBase(0);
		gameObj->SetMapBaseCode(99);
		mTiles[3][8] = gameObj;

		gameObj = ch::object::Instantiate<newroad_0>(MapPosCalc(3, 9), eColliderLayer::Tile); //���� ��
		gameObj->SetTileType(0);
		gameObj->SetTileBase(0);
		gameObj->SetMapBaseCode(99);
		mTiles[3][9] = gameObj;

		gameObj = ch::object::Instantiate<newroad_0>(MapPosCalc(3, 10), eColliderLayer::Tile); //���� ��
		gameObj->SetTileType(0);
		gameObj->SetTileBase(0);
		gameObj->SetMapBaseCode(99);
		mTiles[3][10] = gameObj;

		gameObj = ch::object::Instantiate<newroad_0>(MapPosCalc(3, 11), eColliderLayer::Tile); //���� ��
		gameObj->SetTileType(0);
		gameObj->SetTileBase(0);
		gameObj->SetMapBaseCode(99);
		mTiles[3][11] = gameObj;
		
		gameObj = ch::object::Instantiate<newroad_3>(MapPosCalc(3, 12), eColliderLayer::Tile); //3�� ��
		gameObj->SetTileType(0);
		gameObj->SetTileBase(0);
		gameObj->SetMapBaseCode(99);
		mTiles[3][12] = gameObj;

		gameObj = ch::object::Instantiate<newroad_4>(MapPosCalc(4,12), eColliderLayer::Tile); //4�� ��
		gameObj->SetTileType(0);
		gameObj->SetTileBase(0);
		gameObj->SetMapBaseCode(99);
		mTiles[4][12] = gameObj;

		gameObj = ch::object::Instantiate<newroad_0>(MapPosCalc(4, 13), eColliderLayer::Tile); //���� ��
		gameObj->SetTileType(0);
		gameObj->SetTileBase(0);
		gameObj->SetMapBaseCode(99);
		mTiles[4][13] = gameObj;

		gameObj = ch::object::Instantiate<newroad_0>(MapPosCalc(4, 14), eColliderLayer::Tile); //���� ��
		gameObj->SetTileType(0);
		gameObj->SetTileBase(0);
		gameObj->SetMapBaseCode(99);
		mTiles[4][14] = gameObj;

		gameObj = ch::object::Instantiate<newroad_0>(MapPosCalc(4, 15), eColliderLayer::Tile); //���� ��
		gameObj->SetTileType(0);
		gameObj->SetTileBase(0);
		gameObj->SetMapBaseCode(99);
		mTiles[4][15] = gameObj;

		gameObj = ch::object::Instantiate<newroad_3>(MapPosCalc(4, 16), eColliderLayer::Tile); //3�� ��
		gameObj->SetTileType(0);
		gameObj->SetTileBase(0);
		gameObj->SetMapBaseCode(99);
		mTiles[4][16] = gameObj;

		gameObj = ch::object::Instantiate<newroad_1>(MapPosCalc(5,16), eColliderLayer::Tile); //���� ��
		gameObj->SetTileType(0);
		gameObj->SetTileBase(0);
		gameObj->SetMapBaseCode(99);
		mTiles[5][16] = gameObj;

		gameObj = ch::object::Instantiate<newroad_1>(MapPosCalc(6, 16), eColliderLayer::Tile); //���� ��
		gameObj->SetTileType(0);
		gameObj->SetTileBase(0);
		gameObj->SetMapBaseCode(99);
		mTiles[6][16] = gameObj;

		gameObj = ch::object::Instantiate<newroad_1>(MapPosCalc(7, 16), eColliderLayer::Tile); //���� ��
		gameObj->SetTileType(0);
		gameObj->SetTileBase(0);
		gameObj->SetMapBaseCode(99);
		mTiles[7][16] = gameObj;

		gameObj = ch::object::Instantiate<newroad_5>(MapPosCalc(8, 16), eColliderLayer::Tile); //5����
		gameObj->SetTileType(0);
		gameObj->SetTileBase(0);
		gameObj->SetMapBaseCode(99);
		mTiles[8][16] = gameObj;

		gameObj = ch::object::Instantiate<newroad_0>(MapPosCalc(8, 15), eColliderLayer::Tile); //���� ��
		gameObj->SetTileType(0);
		gameObj->SetTileBase(0);
		gameObj->SetMapBaseCode(99);
		mTiles[8][15] = gameObj;

		gameObj = ch::object::Instantiate<newroad_4>(MapPosCalc(8, 14), eColliderLayer::Tile); //4�� ��
		gameObj->SetTileType(0);
		gameObj->SetTileBase(0);
		gameObj->SetMapBaseCode(99);
		mTiles[8][14] = gameObj;

		gameObj = ch::object::Instantiate<newroad_3>(MapPosCalc(7, 14), eColliderLayer::Tile); //3�� ��
		gameObj->SetTileType(0);
		gameObj->SetTileBase(0);
		gameObj->SetMapBaseCode(99);
		mTiles[7][14] = gameObj;

		gameObj = ch::object::Instantiate<newroad_0>(MapPosCalc(7,13 ), eColliderLayer::Tile); //���� ��
		gameObj->SetTileType(0);
		gameObj->SetTileBase(0);
		gameObj->SetMapBaseCode(99);
		mTiles[7][13] = gameObj;

		gameObj = ch::object::Instantiate<newroad_2>(MapPosCalc(7,12), eColliderLayer::Tile); //2�� ��    //////////ķ����
		gameObj->SetTileType(0);
		gameObj->SetTileBase(0);
		gameObj->SetMapBaseCode(99);
		mTiles[7][12] = gameObj;


		gameObj = ch::object::Instantiate<newroad_5>(MapPosCalc(8,12 ), eColliderLayer::Tile); //5����
		gameObj->SetTileType(0);
		gameObj->SetTileBase(0);
		gameObj->SetMapBaseCode(99);
		mTiles[8][12] = gameObj;

		gameObj = ch::object::Instantiate<newroad_0>(MapPosCalc(8,11), eColliderLayer::Tile); //���� ��
		gameObj->SetTileType(0);
		gameObj->SetTileBase(0);
		gameObj->SetMapBaseCode(99);
		mTiles[8][11] = gameObj;

		gameObj = ch::object::Instantiate<newroad_0>(MapPosCalc(8, 10), eColliderLayer::Tile); //���� ��
		gameObj->SetTileType(0);
		gameObj->SetTileBase(0);
		gameObj->SetMapBaseCode(99);
		mTiles[8][10] = gameObj;

		gameObj = ch::object::Instantiate<newroad_0>(MapPosCalc(8, 9), eColliderLayer::Tile); //���� ��
		gameObj->SetTileType(0);
		gameObj->SetTileBase(0);
		gameObj->SetMapBaseCode(99);
		mTiles[8][9] = gameObj;

		gameObj = ch::object::Instantiate<newroad_0>(MapPosCalc(8, 8), eColliderLayer::Tile); //���� ��
		gameObj->SetTileType(0);
		gameObj->SetTileBase(0);
		gameObj->SetMapBaseCode(99);
		mTiles[8][8] = gameObj;

		gameObj = ch::object::Instantiate<newroad_4>(MapPosCalc(8, 7), eColliderLayer::Tile); //���� ��
		gameObj->SetTileType(0);
		gameObj->SetTileBase(0);
		gameObj->SetMapBaseCode(99);
		mTiles[8][7] = gameObj;

		gameObj = ch::object::Instantiate<newroad_1>(MapPosCalc(7,7 ), eColliderLayer::Tile); //���� ��
		gameObj->SetTileType(0);
		gameObj->SetTileBase(0);
		gameObj->SetMapBaseCode(99);
		mTiles[7][7] = gameObj;

		gameObj = ch::object::Instantiate<newroad_3>(MapPosCalc(6, 7), eColliderLayer::Tile); //3�� ��
		gameObj->SetTileType(0);
		gameObj->SetTileBase(0);
		gameObj->SetMapBaseCode(99);
		mTiles[6][7] = gameObj;

		gameObj = ch::object::Instantiate<newroad_0>(MapPosCalc(6, 6), eColliderLayer::Tile); //���� ��
		gameObj->SetTileType(0);
		gameObj->SetTileBase(0);
		gameObj->SetMapBaseCode(99);
		mTiles[6][6] = gameObj;

		gameObj = ch::object::Instantiate<newroad_4>(MapPosCalc(6, 5), eColliderLayer::Tile); //4�� ��
		gameObj->SetTileType(0);
		gameObj->SetTileBase(0);
		gameObj->SetMapBaseCode(99);
		mTiles[6][5] = gameObj;

		gameObj = ch::object::Instantiate<newroad_1>(MapPosCalc(5,5), eColliderLayer::Tile); //���� ��
		gameObj->SetTileType(0);
		gameObj->SetTileBase(0);
		gameObj->SetMapBaseCode(99);
		mTiles[5][5] = gameObj;

		gameObj = ch::object::Instantiate<newroad_2>(MapPosCalc(4, 5), eColliderLayer::Tile); //2�� ��
		gameObj->SetTileType(0);
		gameObj->SetTileBase(0);
		gameObj->SetMapBaseCode(99);
		mTiles[4][5] = gameObj;

		gameObj = ch::object::Instantiate<newroad_5>(MapPosCalc(4,6), eColliderLayer::Tile); //5����
		gameObj->SetTileType(0);
		gameObj->SetTileBase(0);
		gameObj->SetMapBaseCode(99);
		mTiles[4][6] = gameObj;
	}

	void GameMap::mapBuildCheck(int mTileNum)
	{
		if (mTileNum == 1) 
		{
			
		}
		else if (mTileNum == 2)
		{
		
		}
		else if (mTileNum == 3)
		{

		}
		else if (mTileNum == 4)
		{

		}
		else if (mTileNum == 5)
		{

		}
		else if (mTileNum == 6)
		{

		}
		else if (mTileNum == 7)
		{

		}
		else if (mTileNum == 8)
		{

		}
		else if (mTileNum == 9)
		{

		}
		else if (mTileNum == 10)
		{

		}
	}



	void GameMap::onRoad() 
	{
		for (size_t i = 0; i < 11; i++)
		{
			for (size_t j = 0; j < 21; j++)
			{
				if (mTiles[i][j]->GetMapBaseCode() == 99 && mTiles[i][j]->GetTileType() == 0) //�� �ڵ� �̸鼭 ������ tile�� ������
				{
					TileMapObject* gameObj = ch::object::Instantiate<Place>(MapPosCalc(i, j), eColliderLayer::TilePlace); // ����
					gameObj->SetTileBase(100);
					mTiles[i][j] = gameObj;
				}
			}
		}

	}

	void GameMap::aroundRoad()//�氡
	{
		for (size_t i = 0; i < 11; i++)
		{
			for (size_t j = 0; j < 21; j++)
			{
				if (mTiles[i][j]->GetMapBaseCode() == 10 && mTiles[i][j]->GetTileType() == 0) //�氡 �ڵ� �̸鼭 ������ tile�� ������
				{
					TileMapObject* gameObj = ch::object::Instantiate<Place>(MapPosCalc(i, j), eColliderLayer::TilePlace); // ����
					gameObj->SetTileBase(1);
					mTiles[i][j] = gameObj;

				}
			}
		}

	}
	void GameMap::exAroundRoad()//�氡�� ������ ���
	{
		for (size_t i = 0; i < 11; i++)
		{
			for (size_t j = 0; j < 21; j++)
			{
				if (mTiles[i][j]->GetMapBaseCode() == 0 && mTiles[i][j]->GetTileType() == 0) //�⺻ �ڵ� �̸鼭 �� ���� tile�� ������
				{
					TileMapObject* gameObj = ch::object::Instantiate<Place>(MapPosCalc(i, j), eColliderLayer::TilePlace); // ����
					gameObj->SetTileBase(100);
					mTiles[i][j] = gameObj;
				}
			}
		}

	}

	

	void GameMap::aroundRoadCheck()//���ֺ� üũ
	{
		for (size_t i = 0; i < 11; i++)
		{
			for (size_t j = 0; j < 21; j++)
			{
				

			}
		}
	}

	void GameMap::aroundVilageCheck()//���� üũ 
	{
		for (size_t i = 0; i < 11; i++)
		{
			for (size_t j = 0; j < 21; j++)
			{

		
			}
		}
	}



	void GameMap::initMap()//���̶� ������°� �ʱ�ȭ ���ֱ�
	{
		for (size_t i = 0; i < 11; i++)
		{
			for (size_t j = 0; j < 21; j++)
			{
				TileMapObject* gameObj = ch::object::Instantiate<BasePlace>(MapPosCalc(i, j), eColliderLayer::BackGround); // ����
				gameObj->SetTileBase(1);
				gameObj->SetTileType(0);
				gameObj->SetMapBaseCode(0);
				mTiles[i][j] = gameObj;
			}
		}

		Map1Create();//1�� �ʻ���

		for (size_t a = 0; a < 11; a++)
		{
			for (size_t b = 0; b < 21; b++)
			{
				if (mTiles[a][b]->GetMapBaseCode() == 99)
				{
					initSangHa(a,b); //�氡�ʱ�ȭ
				}
			}
		}



	}
	void GameMap::initSangHa(int y, int x) //���� �¿�
	{
		if (mTiles[y + 1][x]->GetMapBaseCode() != 99)
		{
			if (mTiles[y + 1][x]->GetTileBase() != 1)
			{
				TileMapObject* gameObj = ch::object::Instantiate<BasePlace>(MapPosCalc(y+1, x), eColliderLayer::BackGround); // ��
				gameObj->SetTileBase(1);
				gameObj->SetMapBaseCode(10);
				mTiles[y + 1][x] = gameObj;
			}
		}

		if (mTiles[y - 1][x]->GetMapBaseCode() != 99)
		{
			if (mTiles[y - 1][x]->GetTileBase() != 1)
			{
				TileMapObject* gameObj = ch::object::Instantiate<BasePlace>(MapPosCalc(y-1, x), eColliderLayer::BackGround); // ��
				gameObj->SetTileBase(1);
				gameObj->SetMapBaseCode(10);
				mTiles[y - 1][x] = gameObj;
			}
		}

		if (mTiles[y][x + 1]->GetMapBaseCode() != 99)
		{
			if (mTiles[y][x + 1]->GetTileBase() != 1)
			{
				TileMapObject* gameObj = ch::object::Instantiate<BasePlace>(MapPosCalc(y, x+1), eColliderLayer::BackGround); // ��
				gameObj->SetTileBase(1);
				gameObj->SetMapBaseCode(10);
				mTiles[y][x + 1] = gameObj;
			}
		}

		if (mTiles[y][x - 1]->GetMapBaseCode() != 99)
		{
			if (mTiles[y][x - 1]->GetTileBase() != 1)
			{
				TileMapObject* gameObj = ch::object::Instantiate<BasePlace>(MapPosCalc(y, x-1), eColliderLayer::BackGround); // ��
				gameObj->SetTileBase(1);
				gameObj->SetMapBaseCode(10);
				mTiles[y][x - 1] = gameObj;
			}
		}
	}

	void GameMap::initOnRoad() 
	{
		for (size_t i = 0; i < 11; i++)
		{
			for (size_t j = 0; j < 21; j++)
			{
				if (mTiles[i][j]->GetTileType() == 99) //���� tile type�� 99�̴�.
				{
					TileMapObject* gameObj = ch::object::Instantiate<BasePlace>(MapPosCalc(i, j), eColliderLayer::BackGround); // ����
					gameObj->SetMapBaseCode(99);
					mTiles[i][j] = gameObj;
				}
			}
		}
	}

	/*
	TileBase :
	0 = �ʱ�ȭ
	1 = �Ǽ����� ����
	
	*/

	/*
	MapBaseCode
	0 = �⺻
	10 = �氡
	99 = ��
	
	*/

}

/*
		gameObj = ch::object::Instantiate<newroad_0>(MapPosCalc( , ), eColliderLayer::Tile); //���� ��
		gameObj->SetTileType(99);
		mTiles[y][x] = gameObj;

		gameObj = ch::object::Instantiate<newroad_1>(MapPosCalc( , ), eColliderLayer::Tile); //���� ��
		gameObj->SetTileType(99);
		mTiles[y][x] = gameObj;

		gameObj = ch::object::Instantiate<newroad_2>(MapPosCalc( , ), eColliderLayer::Tile); //2�� ��
		gameObj->SetTileType(99);
		mTiles[y][x] = gameObj;

		gameObj = ch::object::Instantiate<newroad_3>(MapPosCalc( , ), eColliderLayer::Tile); //3�� ��
		gameObj->SetTileType(99);
		mTiles[y][x] = gameObj;

		gameObj = ch::object::Instantiate<newroad_4>(MapPosCalc( , ), eColliderLayer::Tile); //4�� ��
		gameObj->SetTileType(99);
		mTiles[y][x] = gameObj;

		gameObj = ch::object::Instantiate<newroad_5>(MapPosCalc( , ), eColliderLayer::Tile); //5����
		gameObj->SetTileType(99);
		mTiles[y][x] = gameObj;
		*/