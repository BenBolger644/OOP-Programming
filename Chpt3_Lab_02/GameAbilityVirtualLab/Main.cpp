#include <iostream>
#include "Abilities.h"
#include "Runner.h"

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

		std::cout << "Ability Runner\n";
		GameAbility const* abilities[]{ &shield, nullptr, &heal };
		int activated{ activateReady(abilities, 3) };
		std::cout << "Activated: " << activated << "\n";
		std::cout << "Powers: " << shield.power() << " " << heal.power() << "\n";

		std::cout << "Boundary checks\n";
		std::cout << "Empty: " << activateReady(nullptr, 0) << "\n";
		std::cout << "Missing Array: " << activateReady(nullptr, 1) << "\n";

		std::cout << "Owned action\n";
		GameAbility* pOwned{ new HealAbility{7} };
		pOwned->activate();
		delete pOwned;
		pOwned = nullptr;

		std::cout << "Leaving Scope\n";
	}

	return 0;
}