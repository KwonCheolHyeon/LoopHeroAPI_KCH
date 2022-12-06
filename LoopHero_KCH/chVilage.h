#pragma once
#include "TileMapObject.h"

namespace ch
{
	class Image;
	class Vilage : public TileMapObject
	{
	public:
		Vilage();
		Vilage(Vector2 pos);
		~Vilage();

		virtual void Initialize() override;
		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

	private:
		Image* mImage;

	};

}