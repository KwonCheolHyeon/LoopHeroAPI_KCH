#pragma once
#include "chGameObject.h"
namespace ch {
	class Image;
	class GameMap : public GameObject
	{
		//����ִ°�?
		//���ΰ�?
		//�ݰ�� ��ġ�����Ѱ�? (�ֺ��� �������)
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
