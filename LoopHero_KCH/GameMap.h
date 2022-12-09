#pragma once
#include "chGameObject.h"

namespace ch {
	class Image;
	class TileMapObject;
	class GameMap 
	{
		//비어있는가?
		//길인가?
		//금고는 설치가능한가? (주변에 없어야함)
		//
	public:
		static GameMap& Instance()
		{
			static GameMap inst;
			return inst;
		}

		GameMap();
		~GameMap();

		virtual void Initialize() ;
		virtual void Tick() ;
		virtual void Render(HDC hdc) ;

		void SetTileType(int type) {
			mTileType = type;
	
		}

		int GetTileType() { return mTileType; }

		double checkTileType;
		
	private:
		
		int mTileType;
		std::vector<std::vector<TileMapObject*>> mTiles;
		static GameMap inst;

		void Map1Create();

		
		void mapBuildCheck(int a);
		void onRoad();
		void aroundRoad();
		void exceptRoad();


		Vector2 MapPosCalc(int y,int x);
		GameObject ins ;
	};
}
