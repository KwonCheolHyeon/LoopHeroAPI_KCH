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
			chCardSelect = true;
		}

		int GetTileType() { return mTileType; }

		double checkTileType;
		
		bool chCardSelect;//ī�� ���ý� ���� �������� üũ
	private:
		
		int mTileType;
		
		std::vector<std::vector<TileMapObject*>> mTiles; //��ġ������ Ÿ��
		std::vector<std::vector<TileMapObject*>> roadTiles; //���� �����ϸ� �ȴ�
		static GameMap inst;

		void Map1Create();

		
		void mapBuildCheck(int a, int y,int x);
		void onRoad();
		void SangHa();
		void ExSangHa();

		void aroundRoad();
		void exAroundRoad();
		void aroundVillage();


		void initGreen();//�ʷϻ�(�Ǽ� ����) �κ� ����

		//ó�� �� �ʱ�ȭ
		void initSangHa(int y,int x);
		void initOnRoad();
		void initMap();

		Vector2 MapPosCalc(int y,int x);
		GameObject ins ;
	};
}
