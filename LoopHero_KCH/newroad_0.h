#pragma once
#include "TileMapObject.h"

namespace ch {
	class Image;
	class newroad_0 : public TileMapObject
	{
	public:
		newroad_0();
		newroad_0(Vector2 pos);
		~newroad_0();

		virtual void Initialize() override;
		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

	private:
		Image* mImage;


	};
}
