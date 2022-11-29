#pragma once
#include "chGameObject.h"

namespace ch {
	class Image;
	class Campfire : public GameObject
	{
	public:
		Campfire();
		Campfire(Vector2 pos);
		~Campfire();

		virtual void Initialize() override;
		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

	private:
		Image* mImage;


	};
}
