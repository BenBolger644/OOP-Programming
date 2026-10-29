#include "Runner.h"
#include "Abilities.h"

int activateReady(GameAbility const* const* t_abilities, int t_count)
{
	if (t_count < 0 || t_count > 4)
	{
		return -1;
	}

	if (t_count == 0)
	{
		return 0;
	}

	if (t_abilities == nullptr)
	{
		return -1;
	}

	int activated{ 0 };

	for (int i{ 0 }; i < t_count; i++)
	{
		if (t_abilities[i] == nullptr)
		{
			continue;
		}

		if (t_abilities[i]->power() > 0)
		{
			t_abilities[i]->activate();
			++activated;
		}
	}

	return activated;
}