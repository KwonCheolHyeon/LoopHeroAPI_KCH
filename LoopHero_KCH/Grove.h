#pragma once
#include "TileMapObject.h"

namespace ch
{
	class Image;
	class Grove : public TileMapObject
	{
	public:
		Grove();
		Grove(Vector2 pos);
		~Grove();

		virtual void Initialize() override;
		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

	private:
		Image* mImage;



	};
}

