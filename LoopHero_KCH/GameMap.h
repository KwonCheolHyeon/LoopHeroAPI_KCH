#pragma once
#include "chGameObject.h"

namespace ch {
	class Image;
	class TileMapObject;
	class GameMap : public GameObject
	{
		//����ִ°�?
		//���ΰ�?
		//�ݰ�� ��ġ�����Ѱ�? (�ֺ��� �������)
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

	private:
		std::vector<std::vector<TileMapObject*>> mTiles;
		int mTileType;
	};
}
