#include <iostream>
#include "CombatUnit.h"
#include "Archer.h"

int main()
{
	std::cout << "Combat Unit Inheritance Lab\n";

	std::cout << "Base Unit\n";
	{
		CombatUnit guard{ 60 };
		std::cout << "Health: " << guard.health() << "\n";
		std::cout << "Attack: " << guard.attackPower() << "\n";
	}

	std::cout << "Archer Unit\n";
	{
		Archer archer{ 80, 12 };
		std::cout << "Health: " << archer.health() << "\n";
		std::cout << "Attack: " << archer.attackPower() << "\n";
	}

	std::cout << "Copy and Views\n";
	{
		Archer archer{ 80, 12 };
		CombatUnit baseCopy{ archer };
		CombatUnit const& baseView{ archer };
		CombatUnit const* pBase{ &archer };

		std::cout << "Direct Attack: " << archer.attackPower() << "\n";
		std::cout << "Copied Attack: " << baseCopy.attackPower() << "\n";
		std::cout << "Reference Attack: " << pBase->attackPower() << "\n";
		std::cout << "Pointer Attack: " << pBase->attackPower() << "\n";
		std::cout << "Original Attack: " << archer.attackPower() << "\n";
	}

	std::cout << "Known-object cast\n";
	{
		Archer archer{ 75, 9 };
		CombatUnit* pUnit{ &archer };
		Archer* pRecovered{ static_cast<Archer*>(pUnit) };

		std::cout << "Base health: " << pUnit->health() << "\n";
		std::cout << "Recovered Attack: " << pRecovered->attackPower() << "\n";
	}

	return 0;
}