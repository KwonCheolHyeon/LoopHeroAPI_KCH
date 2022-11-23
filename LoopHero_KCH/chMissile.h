#pragma once
#include "chGameObject.h"

namespace ch
{
	class Image;
	class Missile : public GameObject
	{
	public:
		Missile();
		~Missile();

		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

		virtual void OnCollisionEnter(Collider* other) override;
		virtual void OnCollisionStay(Collider* other) override;
		virtual void OnCollisionExit(Collider* other) override;

	private:
		float mSpeed;
		float mAliveTime;
		Image* mImage;
	};
}

