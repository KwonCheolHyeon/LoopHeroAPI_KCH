#include "chComponent.h"
#include "chGameObject.h"
namespace ch
{
	Component::Component(eComponentType type)
		: mType(type)
		, mOwner(nullptr)
	{
	}

	Component::~Component()
	{
	}

	void Component::Tick()
	{
	}

	void Component::Render(HDC hdc)
	{
	}
}