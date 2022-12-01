#pragma once	
#include "TileMapObject.h"

namespace ch {

	class Image;
	class Rock : public TileMapObject
	{
	public:
		Rock();
		Rock(Vector2 pos);
		~Rock();

		virtual void Initialize() override;
		virtual void Tick() override;
		virtual void Render(HDC hdc) override;
		
	private:
		Image* mImage;



	};
}
