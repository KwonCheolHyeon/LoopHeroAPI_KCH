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
			initGreen();
			mTileType = type;
			chCardSelect = true;
		}

		int GetTileType() { return mTileType; }

		double checkTileType;
		
		bool chCardSelect;//ī�� ���ý� ���� �������� üũ


		//�̴� ������
		GameObject *miniWarrior;
		bool miniMoveOn = true;
		double Movetime;
	protected:
		Vector2 MapPosCalcOffset(int y, int x);
		std::vector<std::vector<TileMapObject*>> mTiles; //��ġ������ Ÿ��
		 //���� �����ϸ� �ȴ�
		std::vector<std::vector<TileMapObject*>> roadTiles;
	private:
		
		int mTileType;
		
		
		static GameMap inst;

		void Map1Create();

		
		void mapBuildCheck(int a, int y,int x);

		void onRoad();
		void aroundRoad();
		void exAroundRoad();
		void aroundVillage();
		void cofferCheck();
		void initGreen();//�ʷϻ�(�Ǽ� ����) �κ� ����
		

		//ó�� �� �ʱ�ȭ
		void initSangHa(int y,int x);
		void initMap();
		Vector2 MapPosCalc(int y, int x);
		GameObject ins ;
	};
}
