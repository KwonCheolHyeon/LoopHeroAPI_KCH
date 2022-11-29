#pragma once
#include "chGameObject.h"

namespace ch {

	class Image;
	class SpiderCocoon : public GameObject
	{
	public:
		SpiderCocoon();
		SpiderCocoon(Vector2 pos);
		~SpiderCocoon();

		virtual void Initialize() override;
		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

	private:
		Image* mImage;



	};
}
