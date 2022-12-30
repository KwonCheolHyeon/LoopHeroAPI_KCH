#pragma once
#include "TileMapObject.h"

namespace ch {

	class Image;
	class SpiderCocoon : public TileMapObject
	{
	public:
		SpiderCocoon();
		SpiderCocoon(Vector2 pos);
		~SpiderCocoon();

		virtual void Initialize() override;
		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

		Vector2 InMapPosCalc(Vector2 pos);
		Vector2 MapPosCalc(int y, int x);

	private:
		Image* mImage;
		void CheckRoad();
		void SpiderSpawn();
		Vector2 mypos;
		Vector2 findRoad;
		int TwoDays;
	};
}
