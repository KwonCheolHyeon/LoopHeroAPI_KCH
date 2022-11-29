#pragma once	
#include "chGameObject.h"

namespace ch {

	class Image;
	class Rock : public GameObject
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
