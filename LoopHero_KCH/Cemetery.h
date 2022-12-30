#pragma once
#include "TileMapObject.h"

namespace ch
{
	class Image;
	class Cemetery : public TileMapObject
	{
	public:
		Cemetery();
		Cemetery(Vector2 pos);
		~Cemetery();

		virtual void Initialize() override;
		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

		Vector2 InMapPosCalc(Vector2 pos);
	private:
		Image* mImage;
		void SkeletonSpawn(); // 해당 지역에 스폰 하면됨
		Vector2 mypos;
		Vector2 findRoad;
		int ThreeDays; // 3일에 한번씩 소환 스켈레톤


	};

}

