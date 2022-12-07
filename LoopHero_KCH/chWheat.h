#pragma once
#include "TileMapObject.h"


namespace ch 
{
	class Image;
	class Wheat : public TileMapObject
	{
	public:
		Wheat();
		Wheat(Vector2 pos);
		~Wheat();

		virtual void Initialize() override;
		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

	private:
		Image* mImage;

	};
}