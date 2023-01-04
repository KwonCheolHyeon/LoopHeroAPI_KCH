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
			initGreen();
			mTileType = type;
			chCardSelect = true;
		}

		int GetTileType() { return mTileType; }

		double checkTileType;
		
		bool chCardSelect;//카드 선택시 선택 가능지역 체크


		
		//미니 아이콘 관련
		
		GameObject* miniWarrior;

		std::vector<std::vector<TileMapObject*>>& GetRoadTiles()
		{
			return roadTiles;
		}
		
		Vector2 MapPosCalcOffset(int y, int x);
		static std::vector<std::vector<TileMapObject*>> roadTiles;

		//static std::vector<std::vector<TileMapObject*>> monsterTiles;

	private:
		
		int mTileType;

		std::vector<std::vector<TileMapObject*>> mTiles; //설치가능한 타일
		//길은 삭제하면 안댐
		
		static GameMap inst;

		void Map1Create();

		
		void mapBuildCheck(int a, int y,int x);

		void onRoad();
		void aroundRoad();
		void exAroundRoad();
		void aroundVillage();
		void cofferCheck();
		void initGreen();//초록색(건설 가능) 부분 제거
		

		//처음 맵 초기화
		void initSangHa(int y,int x);
		void initMap();
		Vector2 MapPosCalc(int y, int x);
		GameObject ins ;

		//보스관련
		bool bossCheck();
		bool bossCheckRock;
		GameObject* lager;

	public:
		double InGameDay;

		bool nextDay;

		bool GetnextDay()
		{
			return nextDay;
		}

	};
}
