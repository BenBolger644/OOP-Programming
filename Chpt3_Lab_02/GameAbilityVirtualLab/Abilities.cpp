#include "Abilities.h"
#include <iostream>

GameAbility::GameAbility(int t_power)
	: m_power{ t_power }
{

}

int GameAbility::power() const
{
	return m_power;
}

void GameAbility::activate() const
{
	std::cout << "Generic Ability\n";
}

ShieldAbility::ShieldAbility(int t_power)
	: GameAbility{ t_power }
{

}

void ShieldAbility::activate() const
{
	std::cout << "Shield Power: " << power() << "\n";
}

HealAbility::HealAbility(int t_power)
	: GameAbility{ t_power }
{

}

void HealAbility::activate() const
{
	std::cout << "Healing Points: " << power() << "\n";
}