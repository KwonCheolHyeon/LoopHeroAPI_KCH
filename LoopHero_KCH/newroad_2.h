#pragma once
#include "TileMapObject.h"

namespace ch {
	class Image;
	class newroad_2 : public TileMapObject
	{
	public:
		newroad_2();
		newroad_2(Vector2 pos);
		~newroad_2();

		virtual void Initialize() override;
		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

	private:
		Image* mImage;


	};
}

