#pragma once
#include "chGameObject.h"
namespace ch {
	class Image;
	class GameMap : public GameObject
	{
		//비어있는가?
		//길인가?
		//금고는 설치가능한가? (주변에 없어야함)
		//
		public:
			GameMap();
			~GameMap();

			virtual void Initialize() override;
			virtual void Tick() override;
			virtual void Render(HDC hdc) override;


		private:
			std::vector<std::vector<TileMapObject*>> mTiles;

	};
}
