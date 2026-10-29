#include <iostream>
#include "Abilities.h"

int main()
{
	std::cout << "Game ability lab\n";

	{
		std::cout << "Virtual calls\n";

		ShieldAbility shield{ 20 };
		HealAbility heal{ 15 };
		GameAbility const& view{ shield };

		std::cout << "Direct: ";
		shield.activate();
		std::cout << "Base view: ";
		view.activate();
		std::cout << "Second type: ";
		heal.activate();

		std::cout << "Owned action\n";
		GameAbility* pOwned{ new HealAbility{7} };
		pOwned->activate();
		delete pOwned;
		pOwned = nullptr;

		std::cout << "Leaving Scope\n";
	}

	return 0;
}