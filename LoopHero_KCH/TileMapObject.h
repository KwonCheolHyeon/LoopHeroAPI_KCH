#pragma once
#include "chGameObject.h"

namespace ch
{
	
	class Collider;
	class TileMapObject : public GameObject
	{
	public:
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

	protected:
		int mTileType; // 설치한 타일
		int mTileBase; // 설치가능한 타일일 경우 1 아닌 경우 0
		int MapBaseCode; // 길 코드와 길가 코드 , 그외 구분용

	private :
		
		UINT mIndex;
		UINT mX;
		UINT mY;
		Vector2 mPos;
		Vector2 mScale;
		
	};

}
