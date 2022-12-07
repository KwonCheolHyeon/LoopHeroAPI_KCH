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
	protected:
		int mTileType;

	private :
		
		UINT mIndex;
		UINT mX;
		UINT mY;
		Vector2 mPos;
		Vector2 mScale;
		
	};

}
