#include "chEntity.h"

namespace ch
{
	Entity::Entity()
		: mName(L"")
		, mID((UINT32)this)
	{
	}
	Entity::~Entity()
	{
	}
}