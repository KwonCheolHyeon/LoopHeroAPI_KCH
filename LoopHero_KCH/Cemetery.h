#pragma once
#include "chGameObject.h"

namespace ch
{
	class Image;
	class Cemetery : public GameObject
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

