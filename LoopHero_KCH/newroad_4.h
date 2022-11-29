#pragma once
#include "chGameObject.h"

namespace ch {
	class Image;
	class newroad_4 : public GameObject
	{
	public:
		newroad_4();
		newroad_4(Vector2 pos);
		~newroad_4();

		virtual void Initialize() override;
		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

	private:
		Image* mImage;


	};
}