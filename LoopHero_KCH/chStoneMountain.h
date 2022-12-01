#pragma once
#include "TileMapObject.h"

namespace ch 
{
	class Image;
	class StoneMountain : public TileMapObject
	{
	public:
		StoneMountain();
		StoneMountain(Vector2 pos);
		~StoneMountain();

		virtual void Initialize() override;
		virtual void Tick() override;
		virtual void Render(HDC hdc) override;
		
	private:
		Image* mImage;

	};
}
