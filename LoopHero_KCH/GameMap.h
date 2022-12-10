#pragma once
#include "chGameObject.h"

namespace ch {
	class Image;
	class TileMapObject;
	class GameMap 
	{
		//����ִ°�?
		//���ΰ�?
		//�ݰ�� ��ġ�����Ѱ�? (�ֺ��� �������)
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
		void SangHa();
		void ExSangHa();

		void aroundRoad();
		void exAroundRoad();
		
		void aroundRoadCheck();
		void aroundVilageCheck();


		//ó�� �� �ʱ�ȭ
		void initSangHa(int y,int x);
		void initOnRoad();
		void initMap();

		Vector2 MapPosCalc(int y,int x);
		GameObject ins ;
	};
}
