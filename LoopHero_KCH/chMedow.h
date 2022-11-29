#pragma once
#include "chGameObject.h"

namespace ch {
	class Image;
	class Medow : public GameObject
	{
	public:
		Medow();
		Medow(Vector2 pos);
		~Medow();

		virtual void Initialize() override;
		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

	private:
		Image* mImage;


	};
}
