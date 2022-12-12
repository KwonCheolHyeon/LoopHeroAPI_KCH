#include "GameMap.h"
#include "TileMapObject.h"
#include "chApplication.h"
#include "chInput.h"
#include "chImage.h"
#include "chObject.h"
#include "chResources.h"
#include "chObject.h"
#include "chTime.h"
#include "TileHeaderFiles.h"
#include "WarriorMini.h"
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
		roadTiles.resize(11);
		for (size_t i = 0; i < 11; i++)
		{
			roadTiles[i].resize(21);
		}
	}

	GameMap::~GameMap()
	{

	}
	void GameMap::Initialize()
	{
		initMap();//�ʱ�ȭ
		ch::object::Instantiate<WarriorMini>(eColliderLayer::PlayerMini);
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
	
			Vector2 objectPos = indexPos;

			if (y >= 0 && y < 11 && x >= 0 && x < 21)
			{
				mapBuildCheck(mTileType, y, x);

				/*
				
				else if (mTileType == 7)
				{
					if (mTiles[y][x] == nullptr)
					{
						
					}
				}
				else if (mTileType == 8)
				{
					if (mTiles[y][x] == nullptr)
					{
						
					}
				}
				else if (mTileType == 9)
				{
					if (mTiles[y][x] == nullptr)
					{
					
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
			*/
			}
		}


		if (mTileType == 1 && chCardSelect == true)//��
		{
			chCardSelect = false;
			exAroundRoad();

		}
		else if (mTileType == 2 && chCardSelect == true) // ��
		{
			chCardSelect = false;
			exAroundRoad();
		}
		else if (mTileType == 3 && chCardSelect == true) // �����̾�
		{
			chCardSelect = false;
			aroundRoad();

		}
		else if (mTileType == 4 && chCardSelect == true)//�Ź�
		{
			chCardSelect = false;
			aroundRoad();

		}
		else if (mTileType == 5 && chCardSelect == true)//����ī��
		{
			chCardSelect = false;
			

		}
		else if (mTileType == 6 && chCardSelect == true) // ��
		{
			chCardSelect = false;
			onRoad();

		}
		else if (mTileType == 7 && chCardSelect == true) // ��
		{
			chCardSelect = false;
			onRoad();

		}
		else if (mTileType == 8 && chCardSelect == true) // ����
		{
			chCardSelect = false;
			onRoad();

		}
		else if (mTileType == 9 && chCardSelect == true) // �ݰ�
		{
			chCardSelect = false;
			cofferCheck();

		}
		else if (mTileType == 10 && chCardSelect == true) // �й�
		{
			chCardSelect = false;
			aroundVillage();

		}

		


		if (KEY_DOWN(eKeyCode::Q)) 
		{
			onRoad();
		}
		if (KEY_DOWN(eKeyCode::W))
		{
			aroundRoad();
		}
		if (KEY_DOWN(eKeyCode::E))
		{
			exAroundRoad();
		}
		if (KEY_DOWN(eKeyCode::R))
		{
			initGreen();
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

		TileMapObject* roadgameObj = ch::object::Instantiate<newroad_2>(MapPosCalc(3, 6), eColliderLayer::Road); //2�� ��
		roadgameObj->SetTileType(0);
		roadgameObj->SetTileBase(0);
		roadgameObj->SetMapBaseCode(99);
		roadTiles[3][6] = roadgameObj;
		

		roadgameObj = ch::object::Instantiate<newroad_0>(MapPosCalc(3, 7), eColliderLayer::Road); //���� ��
		roadgameObj->SetTileType(0);
		roadgameObj->SetTileBase(0);
		roadgameObj->SetMapBaseCode(99);
		roadTiles[3][7] = roadgameObj;
		

		roadgameObj = ch::object::Instantiate<newroad_0>(MapPosCalc(3, 8), eColliderLayer::Road); //���� ��
		roadgameObj->SetTileType(0);
		roadgameObj->SetTileBase(0);
		roadgameObj->SetMapBaseCode(99);
		roadTiles[3][8] = roadgameObj;
		

		roadgameObj = ch::object::Instantiate<newroad_0>(MapPosCalc(3, 9), eColliderLayer::Road); //���� ��
		roadgameObj->SetTileType(0);
		roadgameObj->SetTileBase(0);
		roadgameObj->SetMapBaseCode(99);
		roadTiles[3][9] = roadgameObj;
		

		roadgameObj = ch::object::Instantiate<newroad_0>(MapPosCalc(3, 10), eColliderLayer::Road); //���� ��
		roadgameObj->SetTileType(0);
		roadgameObj->SetTileBase(0);
		roadgameObj->SetMapBaseCode(99);
		roadTiles[3][10] = roadgameObj;
		

		roadgameObj = ch::object::Instantiate<newroad_0>(MapPosCalc(3, 11), eColliderLayer::Road); //���� ��
		roadgameObj->SetTileType(0);
		roadgameObj->SetTileBase(0);
		roadgameObj->SetMapBaseCode(99);
		roadTiles[3][11] = roadgameObj;
		

		roadgameObj = ch::object::Instantiate<newroad_3>(MapPosCalc(3, 12), eColliderLayer::Road); //3�� ��
		roadgameObj->SetTileType(0);
		roadgameObj->SetTileBase(0);
		roadgameObj->SetMapBaseCode(99);
		roadTiles[3][12] = roadgameObj;
		

		roadgameObj = ch::object::Instantiate<newroad_4>(MapPosCalc(4, 12), eColliderLayer::Road); //4�� ��
		roadgameObj->SetTileType(0);
		roadgameObj->SetTileBase(0);
		roadgameObj->SetMapBaseCode(99);
		roadTiles[4][12] = roadgameObj;
		

		roadgameObj = ch::object::Instantiate<newroad_0>(MapPosCalc(4, 13), eColliderLayer::Road); //���� ��
		roadgameObj->SetTileType(0);
		roadgameObj->SetTileBase(0);
		roadgameObj->SetMapBaseCode(99);
		roadTiles[4][13] = roadgameObj;
		

		roadgameObj = ch::object::Instantiate<newroad_0>(MapPosCalc(4, 14), eColliderLayer::Road); //���� ��
		roadgameObj->SetTileType(0);
		roadgameObj->SetTileBase(0);
		roadgameObj->SetMapBaseCode(99);
		roadTiles[4][14] = roadgameObj;
		

		roadgameObj = ch::object::Instantiate<newroad_0>(MapPosCalc(4, 15), eColliderLayer::Road); //���� ��
		roadgameObj->SetTileType(0);
		roadgameObj->SetTileBase(0);
		roadgameObj->SetMapBaseCode(99);
		roadTiles[4][15] = roadgameObj;
		

		roadgameObj = ch::object::Instantiate<newroad_3>(MapPosCalc(4, 16), eColliderLayer::Road); //3�� ��
		roadgameObj->SetTileType(0);
		roadgameObj->SetTileBase(0);
		roadgameObj->SetMapBaseCode(99);
		roadTiles[4][16] = roadgameObj;
		

		roadgameObj = ch::object::Instantiate<newroad_1>(MapPosCalc(5, 16), eColliderLayer::Road); //���� ��
		roadgameObj->SetTileType(0);
		roadgameObj->SetTileBase(0);
		roadgameObj->SetMapBaseCode(99);
		roadTiles[5][16] = roadgameObj;
		

		roadgameObj = ch::object::Instantiate<newroad_1>(MapPosCalc(6, 16), eColliderLayer::Road); //���� ��
		roadgameObj->SetTileType(0);
		roadgameObj->SetTileBase(0);
		roadgameObj->SetMapBaseCode(99);
		roadTiles[6][16] = roadgameObj;
		

		roadgameObj = ch::object::Instantiate<newroad_1>(MapPosCalc(7, 16), eColliderLayer::Road); //���� ��
		roadgameObj->SetTileType(0);
		roadgameObj->SetTileBase(0);
		roadgameObj->SetMapBaseCode(99);
		roadTiles[7][16] = roadgameObj;
		

		roadgameObj = ch::object::Instantiate<newroad_5>(MapPosCalc(8, 16), eColliderLayer::Road); //5����
		roadgameObj->SetTileType(0);
		roadgameObj->SetTileBase(0);
		roadgameObj->SetMapBaseCode(99);
		roadTiles[8][16] = roadgameObj;
		

		roadgameObj = ch::object::Instantiate<newroad_0>(MapPosCalc(8, 15), eColliderLayer::Road); //���� ��
		roadgameObj->SetTileType(0);
		roadgameObj->SetTileBase(0);
		roadgameObj->SetMapBaseCode(99);
		roadTiles[8][15] = roadgameObj;
		

		roadgameObj = ch::object::Instantiate<newroad_4>(MapPosCalc(8, 14), eColliderLayer::Road); //4�� ��
		roadgameObj->SetTileType(0);
		roadgameObj->SetTileBase(0);
		roadgameObj->SetMapBaseCode(99);
		roadTiles[8][14] = roadgameObj;
		

		roadgameObj = ch::object::Instantiate<newroad_3>(MapPosCalc(7, 14), eColliderLayer::Road); //3�� ��
		roadgameObj->SetTileType(0);
		roadgameObj->SetTileBase(0);
		roadgameObj->SetMapBaseCode(99);
		roadTiles[7][14] = roadgameObj;
		

		roadgameObj = ch::object::Instantiate<newroad_0>(MapPosCalc(7, 13), eColliderLayer::Road); //���� ��
		roadgameObj->SetTileType(0);
		roadgameObj->SetTileBase(0);
		roadgameObj->SetMapBaseCode(99);
		roadTiles[7][13] = roadgameObj;
		

		
		ch::object::Instantiate<Lager>(eColliderLayer::Tile);  //ķ����
		roadgameObj = ch::object::Instantiate<newroad_2>(MapPosCalc(7, 12), eColliderLayer::Road); //2�� ��    //////////ķ����
		roadgameObj->SetTileType(0);
		roadgameObj->SetTileBase(0);
		roadgameObj->SetMapBaseCode(100);
		roadTiles[7][12] = roadgameObj;
		

		roadgameObj = ch::object::Instantiate<newroad_5>(MapPosCalc(8, 12), eColliderLayer::Road); //5����
		roadgameObj->SetTileType(0);
		roadgameObj->SetTileBase(0);
		roadgameObj->SetMapBaseCode(99);
		roadTiles[8][12] = roadgameObj;
		

		roadgameObj = ch::object::Instantiate<newroad_0>(MapPosCalc(8, 11), eColliderLayer::Road); //���� ��
		roadgameObj->SetTileType(0);
		roadgameObj->SetTileBase(0);
		roadgameObj->SetMapBaseCode(99);
		roadTiles[8][11] = roadgameObj;
		

		roadgameObj = ch::object::Instantiate<newroad_0>(MapPosCalc(8, 10), eColliderLayer::Road); //���� ��
		roadgameObj->SetTileType(0);
		roadgameObj->SetTileBase(0);
		roadgameObj->SetMapBaseCode(99);
		roadTiles[8][10] = roadgameObj;
		

		roadgameObj = ch::object::Instantiate<newroad_0>(MapPosCalc(8, 9), eColliderLayer::Road); //���� ��
		roadgameObj->SetTileType(0);
		roadgameObj->SetTileBase(0);
		roadgameObj->SetMapBaseCode(99);
		roadTiles[8][9] = roadgameObj;
		

		roadgameObj = ch::object::Instantiate<newroad_0>(MapPosCalc(8, 8), eColliderLayer::Road); //���� ��
		roadgameObj->SetTileType(0);
		roadgameObj->SetTileBase(0);
		roadgameObj->SetMapBaseCode(99);
		roadTiles[8][8] = roadgameObj;
		

		roadgameObj = ch::object::Instantiate<newroad_4>(MapPosCalc(8, 7), eColliderLayer::Road); //���� ��
		roadgameObj->SetTileType(0);
		roadgameObj->SetTileBase(0);
		roadgameObj->SetMapBaseCode(99);
		roadTiles[8][7] = roadgameObj;
		

		roadgameObj = ch::object::Instantiate<newroad_1>(MapPosCalc(7, 7), eColliderLayer::Road); //���� ��
		roadgameObj->SetTileType(0);
		roadgameObj->SetTileBase(0);
		roadgameObj->SetMapBaseCode(99);
		roadTiles[7][7] = roadgameObj;
		

		roadgameObj = ch::object::Instantiate<newroad_3>(MapPosCalc(6, 7), eColliderLayer::Road); //3�� ��
		roadgameObj->SetTileType(0);
		roadgameObj->SetTileBase(0);
		roadgameObj->SetMapBaseCode(99);
		roadTiles[6][7] = roadgameObj;
		

		roadgameObj = ch::object::Instantiate<newroad_0>(MapPosCalc(6, 6), eColliderLayer::Road); //���� ��
		roadgameObj->SetTileType(0);
		roadgameObj->SetTileBase(0);
		roadgameObj->SetMapBaseCode(99);
		roadTiles[6][6] = roadgameObj;
		

		roadgameObj = ch::object::Instantiate<newroad_4>(MapPosCalc(6, 5), eColliderLayer::Road); //4�� ��
		roadgameObj->SetTileType(0);
		roadgameObj->SetTileBase(0);
		roadgameObj->SetMapBaseCode(99);
		roadTiles[6][5] = roadgameObj;
		

		roadgameObj = ch::object::Instantiate<newroad_1>(MapPosCalc(5, 5), eColliderLayer::Road); //���� ��
		roadgameObj->SetTileType(0);
		roadgameObj->SetTileBase(0);
		roadgameObj->SetMapBaseCode(99);
		roadTiles[5][5] = roadgameObj;
		

		roadgameObj = ch::object::Instantiate<newroad_2>(MapPosCalc(4, 5), eColliderLayer::Road); //2�� ��
		roadgameObj->SetTileType(0);
		roadgameObj->SetTileBase(0);
		roadgameObj->SetMapBaseCode(99);
		roadTiles[4][5] = roadgameObj;
		

		roadgameObj = ch::object::Instantiate<newroad_5>(MapPosCalc(4, 6), eColliderLayer::Road); //5����
		roadgameObj->SetTileType(0);
		roadgameObj->SetTileBase(0);
		roadgameObj->SetMapBaseCode(99);
		roadTiles[4][6] = roadgameObj;
		

	}

	void GameMap::mapBuildCheck(int mTileNum,int y,int x)
	{
		if (mTileNum == 1)
		{
			if (mTiles[y][x]->GetTileBase() == 1) { //��ġ ���� ���� 
				
				if (KEY_DOWN(eKeyCode::LBTN))
				{
					initGreen();
				}
				TileMapObject* gameObj = ch::object::Instantiate<StoneMountain>(MapPosCalc(y, x), eColliderLayer::Tile); //��
				gameObj->SetTileType(1);
				mTiles[y][x] = gameObj;
				mTileType = 0;
			}
		}
		else if (mTileNum == 2)
		{
			if (mTiles[y][x]->GetTileBase() == 1) { //��ġ ���� ���� 

				if (KEY_DOWN(eKeyCode::LBTN))
				{
					initGreen();
				}
				TileMapObject* gameObj = ch::object::Instantiate<Rock>(MapPosCalc(y, x), eColliderLayer::Tile); //����
				gameObj->SetTileType(2);
				mTiles[y][x] = gameObj;
				mTileType = 0;
			}
		}
		else if (mTileNum == 3)
		{
			if (mTiles[y][x]->GetTileBase() == 1) { //��ġ ���� ���� 

				if (KEY_DOWN(eKeyCode::LBTN))
				{
					initGreen();
				}
				TileMapObject* gameObj = ch::object::Instantiate<Vampire_Mansion>(MapPosCalc(y, x), eColliderLayer::Tile); // �����̾���
				gameObj->SetTileType(3);
				mTiles[y][x] = gameObj;
				mTileType = 0;
			}

		}
		else if (mTileNum == 4)
		{
			if (mTiles[y][x]->GetTileBase() == 1) { //��ġ ���� ���� 

				if (KEY_DOWN(eKeyCode::LBTN))
				{
					initGreen();
				}
				TileMapObject* gameObj = ch::object::Instantiate<SpiderCocoon>(MapPosCalc(y, x), eColliderLayer::Tile); // �Ź̰�ġ
				gameObj->SetTileType(4);
				mTiles[y][x] = gameObj;
				mTileType = 0;
			}

		}
		else if (mTileNum == 5)
		{
			if (mTiles[y][x]->GetMapBaseCode() == 99 && mTiles[y][x] != nullptr) //���� ���
			{
				mTiles[y][x]->Death();
				TileMapObject* gameObj = ch::object::Instantiate<BasePlace>(MapPosCalc(y, x), eColliderLayer::BackGround); // ����
				gameObj->SetTileType(0);
				mTiles[y][x] = gameObj;
			}
			else if ((mTiles[y][x]->GetMapBaseCode() == 0 || mTiles[y][x]->GetMapBaseCode() == 10) && mTiles[y][x] != nullptr) //����� ��� 
			{
				mTiles[y][x]->Death();
				TileMapObject* gameObj = ch::object::Instantiate<BasePlace>(MapPosCalc(y, x), eColliderLayer::BackGround); // ����
				gameObj->SetTileType(0);
				mTiles[y][x] = gameObj;
			}
		}
		else if (mTileNum == 6)
		{
			if (mTiles[y][x]->GetTileBase() == 1) { //��ġ ���� ���� 

				if (KEY_DOWN(eKeyCode::LBTN))
				{
					initGreen();
				}
				TileMapObject* gameObj = ch::object::Instantiate<Vilage>(MapPosCalc(y, x), eColliderLayer::Tile); // ����
				gameObj->SetTileType(6);
				mTiles[y][x] = gameObj;
				mTileType = 0;
			}

		}
		else if (mTileNum == 7)
		{
			if (mTiles[y][x]->GetTileBase() == 1) { //��ġ ���� ���� 

				if (KEY_DOWN(eKeyCode::LBTN))
				{
					initGreen();
				}
				TileMapObject* gameObj = ch::object::Instantiate<Grove>(MapPosCalc(y, x), eColliderLayer::Tile); // ��
				gameObj->SetTileType(7);
				mTiles[y][x] = gameObj;
				mTileType = 0;
			}
		}
		else if (mTileNum == 8)
		{
			if (mTiles[y][x]->GetTileBase() == 1) { //��ġ ���� ���� 

				if (KEY_DOWN(eKeyCode::LBTN))
				{
					initGreen();
				}
				TileMapObject* gameObj = ch::object::Instantiate<Cemetery>(MapPosCalc(y, x), eColliderLayer::Tile); // ����
				gameObj->SetTileType(8);
				mTiles[y][x] = gameObj;
				mTileType = 0;
			}
		}
		else if (mTileNum == 9)
		{
			if (mTiles[y][x]->GetTileBase() == 1) { //��ġ ���� ���� 

				if (KEY_DOWN(eKeyCode::LBTN))
				{
					initGreen();
				}
				TileMapObject* gameObj = ch::object::Instantiate<Coffers>(MapPosCalc(y, x), eColliderLayer::Tile); // �ݰ�
				gameObj->SetTileType(9);
				mTiles[y][x] = gameObj;
				mTileType = 0;
			}
		}
		else if (mTileNum == 10)
		{
			if (mTiles[y][x]->GetTileBase() == 1) { //��ġ ���� ���� 

				if (KEY_DOWN(eKeyCode::LBTN))
				{
					initGreen();
				}
				TileMapObject* gameObj = ch::object::Instantiate<Wheat>(MapPosCalc(y, x), eColliderLayer::Tile); // �й�
				gameObj->SetTileType(10);
				mTiles[y][x] = gameObj;
				mTileType = 0;
			}
		}
	}

	void GameMap::onRoad()//����  
	{
		for (size_t i = 0; i < 11; i++)
		{
			for (size_t j = 0; j < 21; j++)
			{
				if (roadTiles[i][j]->GetMapBaseCode() == 99 && mTiles[i][j]->GetTileType() == 0) //�� �ڵ� �̸鼭 ������ tile�� ������
				{
					TileMapObject* gameObj = ch::object::Instantiate<Place>(MapPosCalc(i, j), eColliderLayer::TilePlace); // ����
					gameObj->SetTileBase(1);
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
				if (roadTiles[i][j]->GetMapBaseCode() == 10 && mTiles[i][j]->GetTileType() == 0) //�氡 �ڵ� �̸鼭 ������ tile�� ������
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
				if (roadTiles[i][j]->GetMapBaseCode() == 0 && mTiles[i][j]->GetTileType() == 0) //�⺻ �ڵ� �̸鼭 �� ���� tile�� ������
				{
					TileMapObject* gameObj = ch::object::Instantiate<Place>(MapPosCalc(i, j), eColliderLayer::TilePlace); //
					gameObj->SetTileBase(1);
					mTiles[i][j] = gameObj;
				}
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

				gameObj->SetTileBase(0);
				gameObj->SetTileType(0);
				gameObj->SetMapBaseCode(0);

				mTiles[i][j] = gameObj;
				roadTiles[i][j] = gameObj;
				
			}
		}

		Map1Create();//1�� �ʻ���

		for (size_t a = 0; a < 11; a++)
		{
			for (size_t b = 0; b < 21; b++)
			{
				if (roadTiles[a][b]->GetMapBaseCode() == 99)
				{
					initSangHa(a, b); //�氡�ʱ�ȭ
				}
			}
		}

		for (size_t a = 0; a < 11; a++)
		{
			for (size_t b = 0; b < 21; b++)
			{
				if (roadTiles[a][b]->GetTileBase() == 1)
				{
					roadTiles[a][b]->SetTileBase(0);
				}
			}
		}

	}

	void GameMap::initSangHa(int y, int x) //���� �¿�
	{
		if (roadTiles[y + 1][x]->GetMapBaseCode() != 99)
		{
			if (roadTiles[y + 1][x]->GetTileBase() != 1)
			{
				TileMapObject* gameObj = ch::object::Instantiate<BasePlace>(MapPosCalc(y + 1, x), eColliderLayer::BackGround); // ��
				gameObj->SetTileBase(1);
				gameObj->SetMapBaseCode(10);
				roadTiles[y + 1][x] = gameObj;
			}
		}

		if (roadTiles[y - 1][x]->GetMapBaseCode() != 99)
		{
			if (roadTiles[y - 1][x]->GetTileBase() != 1)
			{
				TileMapObject* gameObj = ch::object::Instantiate<BasePlace>(MapPosCalc(y - 1, x), eColliderLayer::BackGround); // ��
				gameObj->SetTileBase(1);
				gameObj->SetMapBaseCode(10);
				roadTiles[y - 1][x] = gameObj;
			}
		}

		if (roadTiles[y][x + 1]->GetMapBaseCode() != 99)
		{
			if (roadTiles[y][x + 1]->GetTileBase() != 1)
			{
				TileMapObject* gameObj = ch::object::Instantiate<BasePlace>(MapPosCalc(y, x + 1), eColliderLayer::BackGround); // ��
				gameObj->SetTileBase(1);
				gameObj->SetMapBaseCode(10);
				roadTiles[y][x + 1] = gameObj;
			}
		}

		if (roadTiles[y][x - 1]->GetMapBaseCode() != 99)
		{
			if (roadTiles[y][x - 1]->GetTileBase() != 1)
			{
				TileMapObject* gameObj = ch::object::Instantiate<BasePlace>(MapPosCalc(y, x - 1), eColliderLayer::BackGround); // ��
				gameObj->SetTileBase(1);
				gameObj->SetMapBaseCode(10);
				roadTiles[y][x - 1] = gameObj;
			}
		}

	}

	void GameMap::initGreen() //�Ǽ� ���� ���� ����
	{
		for (size_t i = 0; i < 11; i++)
		{
			for (size_t j = 0; j < 21; j++)
			{
				if (mTiles[i][j]->GetTileBase() == 1)
				{
					mTiles[i][j]->Death();
					//mTiles[i][j] = nullptr;  // �̰� ����� ���� �ִ���???????
					TileMapObject* gameObj = ch::object::Instantiate<BasePlace>(MapPosCalc(i, j), eColliderLayer::BackGround); // ����
					gameObj->SetTileBase(0);
					gameObj->SetTileType(0);
					mTiles[i][j] = gameObj;
				}
			}
		}
	}

	void GameMap::aroundVillage() 
	{
		for (size_t i = 0; i < 11; i++)
		{
			for (size_t j = 0; j < 21; j++)
			{
				if (mTiles[i][j]->GetTileType() == 6)
				{
					if (roadTiles[i + 1][j]->GetMapBaseCode() == 99 && mTiles[i + 1][j]->GetTileType() == 0)
					{
						TileMapObject* gameObj = ch::object::Instantiate<Place>(MapPosCalc(i + 1, j), eColliderLayer::TilePlace); // 
						gameObj->SetTileBase(1);
						mTiles[i + 1][j] = gameObj;
					}
					if (roadTiles[i - 1][j]->GetMapBaseCode() == 99 && mTiles[i - 1][j]->GetTileType() == 0)
					{
						TileMapObject* gameObj = ch::object::Instantiate<Place>(MapPosCalc(i - 1, j), eColliderLayer::TilePlace); // 
						gameObj->SetTileBase(1);
						mTiles[i - 1][j] = gameObj;
					}
					if (roadTiles[i][j + 1]->GetMapBaseCode() == 99 && mTiles[i][j + 1]->GetTileType() == 0)
					{
						TileMapObject* gameObj = ch::object::Instantiate<Place>(MapPosCalc(i, j + 1), eColliderLayer::TilePlace); // 
						gameObj->SetTileBase(1);
						mTiles[i][j + 1] = gameObj;
					}
					if (roadTiles[i][j - 1]->GetMapBaseCode() == 99 && mTiles[i][j - 1]->GetTileType() == 0)
					{
						TileMapObject* gameObj = ch::object::Instantiate<Place>(MapPosCalc(i, j - 1), eColliderLayer::TilePlace); //
						gameObj->SetTileBase(1);
						mTiles[i][j - 1] = gameObj;
					}
				}
			}
		}
	}

	void GameMap::cofferCheck() 
	{
		exAroundRoad();
		for (size_t i = 0; i < 11; i++)
		{
			for (size_t j = 0; j < 21; j++)
			{	
				if (( (roadTiles[i][j]->GetMapBaseCode() == 0 || roadTiles[i][j]->GetMapBaseCode() == 10) && mTiles[i][j]->GetTileType() >= 1 ) || roadTiles[i][j]->GetMapBaseCode() == 99) //ù��° ���� (�氡 �Ǵ� ���̾ƴ� ���) �׸��� �� Ÿ�Ͽ� Ÿ���� ������ �Ǵ� ������¿�
				{
					if (mTiles[i - 1][j] != nullptr && mTiles[i-1][j]->GetTileBase() == 1)
					{
						mTiles[i-1][j]->Death();
						//mTiles[i][j] = nullptr;  // �̰� ����� ���� �ִ���???????
						TileMapObject* gameObj = ch::object::Instantiate<BasePlace>(MapPosCalc(i-1, j), eColliderLayer::BackGround); // ����
						gameObj->SetTileBase(0);
						gameObj->SetTileType(0);
						mTiles[i-1][j] = gameObj;
					}
					if (mTiles[i + 1][j] != nullptr && mTiles[i+1][j]->GetTileBase() == 1)
					{
						mTiles[i+1][j]->Death();
						//mTiles[i][j] = nullptr;  // �̰� ����� ���� �ִ���???????
						TileMapObject* gameObj = ch::object::Instantiate<BasePlace>(MapPosCalc(i+1, j), eColliderLayer::BackGround); // ����
						gameObj->SetTileBase(0);
						gameObj->SetTileType(0);
						mTiles[i+1][j] = gameObj;
					}
					if (mTiles[i][j-1] != nullptr && mTiles[i][j-1]->GetTileBase() == 1)
					{
						mTiles[i][j-1]->Death();
						//mTiles[i][j] = nullptr;  // �̰� ����� ���� �ִ���???????
						TileMapObject* gameObj = ch::object::Instantiate<BasePlace>(MapPosCalc(i, j-1), eColliderLayer::BackGround); // ����
						gameObj->SetTileBase(0);
						gameObj->SetTileType(0);
						mTiles[i][j-1] = gameObj;
					}
					if (mTiles[i][j + 1] != nullptr && mTiles[i][j+1]->GetTileBase() == 1)
					{
						mTiles[i][j+1]->Death();
						//mTiles[i][j] = nullptr;  // �̰� ����� ���� �ִ���???????
						TileMapObject* gameObj = ch::object::Instantiate<BasePlace>(MapPosCalc(i, j+1), eColliderLayer::BackGround); // ����
						gameObj->SetTileBase(0);
						gameObj->SetTileType(0);
						mTiles[i][j+1] = gameObj;
					}
					if (mTiles[i - 1][j-1] != nullptr && mTiles[i - 1][j-1]->GetTileBase() == 1)
					{
						mTiles[i - 1][j-1]->Death();
						//mTiles[i][j] = nullptr;  // �̰� ����� ���� �ִ���???????
						TileMapObject* gameObj = ch::object::Instantiate<BasePlace>(MapPosCalc(i - 1, j-1), eColliderLayer::BackGround); // ����
						gameObj->SetTileBase(0);
						gameObj->SetTileType(0);
						mTiles[i - 1][j-1] = gameObj;
					}
					if (mTiles[i - 1][j + 1] != nullptr && mTiles[i - 1][j + 1]->GetTileBase() == 1)
					{
						mTiles[i - 1][j + 1]->Death();
						//mTiles[i][j] = nullptr;  // �̰� ����� ���� �ִ���???????
						TileMapObject* gameObj = ch::object::Instantiate<BasePlace>(MapPosCalc(i - 1, j + 1), eColliderLayer::BackGround); // ����
						gameObj->SetTileBase(0);
						gameObj->SetTileType(0);
						mTiles[i - 1][j + 1] = gameObj;
					}
					if (mTiles[i+1][j - 1] != nullptr && mTiles[i+1][j - 1]->GetTileBase() == 1)
					{
						mTiles[i+1][j - 1]->Death();
						//mTiles[i][j] = nullptr;  // �̰� ����� ���� �ִ���???????
						TileMapObject* gameObj = ch::object::Instantiate<BasePlace>(MapPosCalc(i+1, j - 1), eColliderLayer::BackGround); // ����
						gameObj->SetTileBase(0);
						gameObj->SetTileType(0);
						mTiles[i+1][j - 1] = gameObj;
					}
					if (mTiles[i+1][j + 1] != nullptr && mTiles[i+1][j + 1]->GetTileBase() == 1)
					{
						mTiles[i+1][j + 1]->Death();
						//mTiles[i][j] = nullptr;  // �̰� ����� ���� �ִ���???????
						TileMapObject* gameObj = ch::object::Instantiate<BasePlace>(MapPosCalc(i+1, j + 1), eColliderLayer::BackGround); // ����
						gameObj->SetTileBase(0);
						gameObj->SetTileType(0);
						mTiles[i+1][j + 1] = gameObj;
					}
				}
				if (i == 0 || i==10 || j ==0 || j==20) 
				{
					mTiles[i][j]->Death();
					//mTiles[i][j] = nullptr;  // �̰� ����� ���� �ִ���???????
					TileMapObject* gameObj = ch::object::Instantiate<BasePlace>(MapPosCalc(i, j), eColliderLayer::BackGround); // ����
					gameObj->SetTileBase(0);
					gameObj->SetTileType(0);
					mTiles[i][j] = gameObj;
				}
				
			}
		}
		
	}



}
	/*
	mTileBase :
	0 = �ʱ�ȭ // �Ǽ��Ұ� �⺻������ 0
	1 = �Ǽ����� ����
	
	
	MapBaseCode
	0 = �⺻
	10 = �氡
	99 = ��
	100 = savePoin
	
	mTiles  : ��ġ�� Ÿ���� ����� ��ġ

	roadTiles : �� Ÿ���� ��ġ

		
		mTileType; // ��ġ�� Ÿ��

		mTileBase; // ��ġ������ Ÿ���� ��� 1 �ƴ� ��� 0

		MapBaseCode; // �� �ڵ�� �氡 �ڵ� , �׿� ���п�
		


	*/



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