#pragma once
#include "chGameObject.h"

namespace ch {
	class Image;
	class TileMapObject;
	class GameMap : public GameObject
	{
		//비어있는가?
		//길인가?
		//금고는 설치가능한가? (주변에 없어야함)
		//
	public:
		static GameMap Instance()
		{
			static GameMap inst;
			return inst;
		}

		GameMap();
		~GameMap();

		virtual void Initialize() override;
		virtual void Tick() override;
		virtual void Render(HDC hdc) override;


		void SetTileType(int type) { mTileType = type; }
		int GetTileType() { return mTileType; }

		Image* GetAtlasImage() { return mImage; }
		void CrateTile(UINT index, Vector2 indexPos);

	private:
		int mTileType;
		Image* mImage;

		std::vector<std::vector<TileMapObject*>> mTilesArrange;

		std::unordered_map<UINT64, TileMapObject*> mTiles;
	};
}
