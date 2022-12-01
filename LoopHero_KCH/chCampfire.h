#pragma once
#include "TileMapObject.h"

namespace ch {
	class Image;
	class Campfire : public TileMapObject
	{
	public:
		Campfire();
		Campfire(Vector2 pos);
		~Campfire();

		virtual void Initialize() override;
		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

	private:
		Image* mImage;


	};
}
