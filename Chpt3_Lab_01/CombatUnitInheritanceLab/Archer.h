#ifndef ARCHER_H
#define ARCHER_H

#include "CombatUnit.h"

class Archer : public CombatUnit
{
public:
	Archer(int t_health, int t_arrowPower);
	~Archer();

	int arrowPower() const;
	int attackPower() const;

private:
	int m_arrowPower;
};

#endif
