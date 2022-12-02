#pragma once

#include "chGameObject.h"


namespace ch 
{
	class MouseObject : public GameObject
	{
	public:
		MouseObject();
		MouseObject(Vector2 position);
		~MouseObject();

		virtual void Initialize();
		virtual void Tick();
		virtual void Render(HDC hdc);

		virtual void OnCollisionEnter(Collider* other);
		virtual void OnCollisionStay(Collider* other);
		virtual void OnCollisionExit(Collider* other);


	private:
		Vector2 mScreenPos;



	};


}
