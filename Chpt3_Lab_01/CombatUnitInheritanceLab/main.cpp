#include <iostream>
#include "CombatUnit.h"

int main()
{
	std::cout << "Combat Unit Inheritance Lab\n";

	std::cout << "Base Unit\n";
	{
		CombatUnit guard{ 60 };
		std::cout << "Health: " << guard.health() << "\n";
		std::cout << "Attack: " << guard.attackPower() << "\n";
	}

	return 0;
}