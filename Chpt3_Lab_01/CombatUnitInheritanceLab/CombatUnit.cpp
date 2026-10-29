#include "CombatUnit.h"
#include <iostream>

CombatUnit::CombatUnit(int t_health)
	: m_health{ t_health }
{
	std::cout << "CombatUnit\n";
}

CombatUnit::~CombatUnit()
{
	std::cout << "- Combat Unit\n";
}

int CombatUnit::health() const
{
	return m_health;
}

int CombatUnit::attackPower() const
{
	return 0;
}