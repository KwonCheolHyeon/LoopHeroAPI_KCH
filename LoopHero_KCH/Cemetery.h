#pragma once
#include "TileMapObject.h"

namespace ch
{
	class Image;
	class Cemetery : public TileMapObject
	{
	public:
		Cemetery();
		Cemetery(Vector2 pos);
		~Cemetery();

		virtual void Initialize() override;
		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

	private:
		Image* mImage;



	};

}

