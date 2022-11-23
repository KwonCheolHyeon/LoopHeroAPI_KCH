#pragma once
#include "chGameObject.h"

namespace ch {
	class LoopMonster
	{
		class Image;
		class Monster : public GameObject
		{
		public:
			Monster();
			Monster(Vector2 position);
			~Monster();

			virtual void Tick() override;
			virtual void Render(HDC hdc) override;

			void Dead();

		private:
			Image* mImage;
			float mTime;
		};

	};
}
