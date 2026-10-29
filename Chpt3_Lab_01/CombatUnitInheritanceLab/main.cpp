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

	return 0;
}