#pragma once
#include "chGameObject.h"

namespace ch
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

		virtual void OnCollisionEnter(Collider* other) override;
		virtual void OnCollisionStay(Collider* other) override;
		virtual void OnCollisionExit(Collider* other) override;

		//void Dead();

	private:
		Image* mImage;
		float mTime;
	};

}