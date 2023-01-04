#pragma once
#include "chGameObject.h"

namespace ch
{
	
	class Collider;
	class TileMapObject : public GameObject
	{
	public:
		enum emonsterType
		{
			Slime,
			Spider,
		};

		TileMapObject();
		TileMapObject(Vector2 position);
		~TileMapObject();

		virtual void Initialize();
		virtual void Tick();
		virtual void Render(HDC hdc);

		void SetIndex(UINT index);
		UINT GetIndex() { return mIndex; }

		void SetPos(Vector2 pos) { mPos = pos; }
		Vector2 GetPos() { return mPos; }
		void SetScale(Vector2 scale) { mScale = scale; }
		Vector2 GetScale() { return mScale; }

		int GetTileType() { return mTileType; }
		void SetTileType(int type) { mTileType = type; }

		int GetTileBase() { return mTileBase; }
		void SetTileBase(int type) { mTileBase = type; }

		int GetMapBaseCode() { return MapBaseCode; }
		void SetMapBaseCode(int type) { MapBaseCode = type; }

		//���� ���� �Լ�
		int GetMonsterType(int a) { return chMonsters[a]; }
		int GetMonsterCount() { return monsterCount; }//���� ��Ÿ���� ������ ������ ������
		void SetMonsters(int monsterIndex);// ���迭�� ���� ������ȣ ���� �־��ִ� �Լ�
		void clearMonsters(); // �� Ŭ����� ���� ���� �ʱ�ȭ ���ִ� �Լ�

	protected:
		int mTileType; // ��ġ�� Ÿ��
		int mTileBase; // ��ġ������ Ÿ���� ��� 1 �ƴ� ��� 0
		int MapBaseCode; // �� �ڵ�� �氡 �ڵ� , �׿� ���п�
		


		//���� ����
		int monsterIndex; // ���� ���� ��ȣ 0 = ����� 1 = ������,  2 = �Ź�, 3 = �����̾�, 4  = �ذ�, 5 = ����  
		int monsterCount; //���Ͱ� ��� �ִ���?
		int chMonsters[5]; // �� �迭�� ���� ���� ��ȣ�� ���� ���� ����


	private :
		
		UINT mIndex;
		UINT mX;
		UINT mY;
		Vector2 mPos;
		Vector2 mScale;
		
	};

}
