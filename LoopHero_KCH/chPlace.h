#pragma once
#include "TileMapObject.h"
namespace ch {

	class Image;
	class Place : public TileMapObject
	{
	public:
		Place();
		Place(Vector2 pos);
		~Place();

		virtual void Initialize() override;
		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

	private:
		Image* mImage;
	};
}


