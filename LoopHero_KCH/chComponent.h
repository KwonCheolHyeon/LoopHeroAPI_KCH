#pragma once
#include "chEntity.h"
#include "Common.h"

namespace ch
{
	class GameObject;
	class Component : public Entity
	{
	public:
		friend class GameObject;
		Component(eComponentType type);
		Component() = delete;
		virtual ~Component();

		virtual void Tick();
		virtual void Render(HDC hdc);

		GameObject* GetOwner() { return mOwner; }

	private:
		const eComponentType mType;
		GameObject* mOwner;
	};
}

