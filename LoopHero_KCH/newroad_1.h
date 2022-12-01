#pragma once
#include "TileMapObject.h"
namespace ch {
	class Image;
	class newroad_1 : public TileMapObject
	{
	public:
		newroad_1();
		newroad_1(Vector2 pos);
		~newroad_1();

		virtual void Initialize() override;
		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

	private:
		Image* mImage;
	};
}

