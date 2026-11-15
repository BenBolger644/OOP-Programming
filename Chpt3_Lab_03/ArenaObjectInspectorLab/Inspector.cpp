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

int requireGuardHealth(ArenaObject const& t_object)
{
	Guard const& guardRef{ dynamic_cast<Guard const&>(t_object) };
	return guardRef.health();
}

int countGuardViews(ArenaObject const* const* t_objects,
    int t_count)
{
    if (t_count < 0 || t_count > 4)
    {
        return -1;
    }

    if (t_count == 0)
    {
        return 0;
    }

    if (t_objects == nullptr)
    {
        return -1;
    }

    int count{ 0 };

    for (int index{ 0 }; index < t_count; ++index)
    {
        if (t_objects[index] == nullptr)
        {
            continue;
        }

        if (dynamic_cast<Guard const*>(t_objects[index]) != nullptr)
        {
            ++count;
        }
    }

    return count;
}  

int countExactGuards(ArenaObject const* const* t_objects,
    int t_count)
{
    if (t_count < 0 || t_count > 4)
    {
        return -1;
    }

    if (t_count == 0)
    {
        return 0;
    }

    if (t_objects == nullptr)
    {
        return -1;
    }

    int count{ 0 };

    for (int index{ 0 }; index < t_count; ++index)
    {
        if (t_objects[index] == nullptr)
        {
            continue;
        }

        if (typeid(*t_objects[index]) == typeid(Guard))
        {
            ++count;
        }
    }

    return count;
}
