#pragma once
#include "chGameObject.h"

namespace ch {
	class Image;
	class newroad_5 : public GameObject
	{
	public:
		newroad_5();
		newroad_5(Vector2 pos);
		~newroad_5();

		virtual void Initialize() override;
		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

	private:
		Image* mImage;


	};
}