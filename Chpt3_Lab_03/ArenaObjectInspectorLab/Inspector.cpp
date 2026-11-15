#include "Inspector.h"
#include "ArenaObjects.h"
#include <typeinfo>

int readGuardHealth(ArenaObject const* t_object)
{
	Guard const* pGuard{ dynamic_cast<Guard const*>(t_object) };

	if (pGuard == nullptr)
	{
		return -1;
	}

	return pGuard->health();
}

bool isExactGuard(ArenaObject const* t_object)
{
	if (t_object == nullptr)
	{
		return false;
	}

	return typeid(*t_object) == typeid(Guard);
}