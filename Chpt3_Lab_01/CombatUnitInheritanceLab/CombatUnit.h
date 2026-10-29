#ifndef COMBAT_UNIT_H
#define COMBAT_UNIT_H

class CombatUnit
{
public:
	explicit CombatUnit(int t_health);
	~CombatUnit();

	int health() const;
	int attackPower() const;

private:
	int m_health;
};

#endif