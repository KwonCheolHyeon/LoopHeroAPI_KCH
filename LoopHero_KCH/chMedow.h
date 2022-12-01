#pragma once
#include "TileMapObject.h"

namespace ch {
	class Image;
	class Medow : public TileMapObject
	{
	public:
		Medow();
		Medow(Vector2 pos);
		~Medow();

		virtual void Initialize() override;
		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

	private:
		Image* mImage;


	};
}
