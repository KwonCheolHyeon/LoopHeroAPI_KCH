#pragma once
#include "chGameObject.h"
#include "TileMapObject.h"
#include <vector>
#include <deque>
namespace ch
{
	class Image;
	class Collider;
	class TileMapObject : public GameObject
	{
	public:
		TileMapObject();
		TileMapObject(Vector2 position);
		~TileMapObject();

		virtual void Initialize(Image* atlas, int index);
		virtual void Tick();
		virtual void Render(HDC hdc);

		void SetIndex(UINT index);
		UINT GetIndex() { return mIndex; }

		void SetPos(Vector2 pos) { mPos = pos; }
		Vector2 GetPos() { return mPos; }
		void SetScale(Vector2 scale) { mScale = scale; }
		Vector2 GetScale() { return mScale; }

		

	private :
		Image* mAtlas;
		UINT mIndex;
		UINT mX;
		UINT mY;
		Vector2 mPos;
		Vector2 mScale;

		std::vector<Image*> ImgVector;
		std::deque<Image*> dequeImag;
	};

}
