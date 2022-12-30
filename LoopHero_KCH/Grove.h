#pragma once
#include "TileMapObject.h"

namespace ch
{
	class Image;
	class Grove : public TileMapObject
	{
	public:
		Grove();
		Grove(Vector2 pos);
		~Grove();

		virtual void Initialize() override;
		virtual void Tick() override;
		virtual void Render(HDC hdc) override;
		Vector2 InMapPosCalc(Vector2 pos);
	private:
		Image* mImage;
		void DogSpawn(); //해당 지역에 스폰 하면 됨
		Vector2 mypos;
		Vector2 findRoad;
		int TwoDays; //2일에 한번씩 들개 소환 


	};
}

