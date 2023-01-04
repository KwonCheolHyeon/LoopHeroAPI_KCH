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

		//몬스터 저장 함수
		int GetMonsterType(int a) { return chMonsters[a]; }
		int GetMonsterCount() { return monsterCount; }//현재 이타일의 몬스터의 개수를 구해줌
		void SetMonsters(int monsterIndex);// 각배열에 몬스터 고유번호 집어 넣어주는 함수
		void clearMonsters(); // 맵 클리어시 맵의 몬스터 초기화 해주는 함수

	protected:
		int mTileType; // 설치한 타일
		int mTileBase; // 설치가능한 타일일 경우 1 아닌 경우 0
		int MapBaseCode; // 길 코드와 길가 코드 , 그외 구분용
		


		//몬스터 저장
		int monsterIndex; // 몬스터 고유 번호 0 = 비었음 1 = 슬라임,  2 = 거미, 3 = 뱀파이어, 4  = 해골, 5 = 하피  
		int monsterCount; //몬스터가 몇마리 있는지?
		int chMonsters[5]; // 각 배열에 몬스터 고유 번호를 집어 넣을 생각


	private :
		
		UINT mIndex;
		UINT mX;
		UINT mY;
		Vector2 mPos;
		Vector2 mScale;
		
	};

}
