#include "Archer.h"
#include <iostream>

Archer::Archer(int t_health, int t_arrowPower)
	: CombatUnit{ t_health }
	, m_arrowPower{ t_arrowPower }
{
	std::cout << "+ archer\n";
}

Archer::~Archer()
{
	std::cout << "- Archer\n";
}

int Archer::arrowPower() const
{
	return m_arrowPower;
}

int Archer::attackPower() const
{
	return m_arrowPower;
}