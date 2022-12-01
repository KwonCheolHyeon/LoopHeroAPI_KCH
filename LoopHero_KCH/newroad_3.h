#pragma once
#include "TileMapObject.h"

namespace ch {
	class Image;
	class newroad_3 : public TileMapObject
	{
	public:
		newroad_3();
		newroad_3(Vector2 pos);
		~newroad_3();

		virtual void Initialize() override;
		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

	private:
		Image* mImage;


	};
}
