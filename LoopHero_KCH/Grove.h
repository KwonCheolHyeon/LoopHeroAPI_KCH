#pragma once
#include "TileMapObject.h"

namespace ch
{
	class Image;
	class Grove : public TileMapObject
	{
	public:
		Grove();
		Grove(Vector2 pos);
		~Grove();

		virtual void Initialize() override;
		virtual void Tick() override;
		virtual void Render(HDC hdc) override;
		Vector2 InMapPosCalc(Vector2 pos);
	private:
		Image* mImage;
		void DogSpawn(); //�ش� ������ ���� �ϸ� ��
		Vector2 mypos;
		Vector2 findRoad;
		int TwoDays; //2�Ͽ� �ѹ��� �鰳 ��ȯ 


	};
}

