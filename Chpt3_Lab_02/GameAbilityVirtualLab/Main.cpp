#include <iostream>
#include "Abilities.h"

int main()
{
	std::cout << "Game Ability lab\n";

	{
		std::cout << "Non-Virtual check\n";

		ShieldAbility shield{ 20 };
		HealAbility heal{ 15 };
		GameAbility const& view{ shield };

		std::cout << "Direct: ";
		shield.activate();
		std::cout << "Base View: ";
		view.activate();
		std::cout << "Second Type: ";
		heal.activate();
	}

	return 0;
}