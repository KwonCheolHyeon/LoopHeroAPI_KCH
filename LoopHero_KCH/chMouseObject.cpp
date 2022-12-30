#include "chMouseObject.h"
#include "chCollider.h"
#include "chInput.h"

namespace ch
{
	MouseObject::MouseObject()
	{
		SetPos(Vector2::Zero);
		SetScale({1.0f,1.0f });

		Collider* collider = new Collider();
		AddComponent(collider);
		collider->SetScale({ 1.0f,1.0f });
	}

	MouseObject::MouseObject(Vector2 position)
	{
	}

	MouseObject::~MouseObject()
	{
	}

	void MouseObject::Initialize()
	{
	}

	void MouseObject::Tick()
	{
		GameObject::Tick();

		Vector2 mousePos = Input::GetMousePos();
		
		SetPos(mousePos);
		
	}

	void MouseObject::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	void MouseObject::OnCollisionEnter(Collider* other)
	{
	}

	void MouseObject::OnCollisionStay(Collider* other)
	{

	}

	void MouseObject::OnCollisionExit(Collider* other)
	{
	}

}