#pragma once
#include "TileMapObject.h"
namespace ch {

	class Image;
	class BasePlace : public TileMapObject
	{
	public:
		BasePlace();
		BasePlace(Vector2 pos);
		~BasePlace();

		virtual void Initialize() override;
		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

	private:
		Image* mImage;
	};
}