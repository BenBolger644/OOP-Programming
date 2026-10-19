#include "Enemy.h"

void Enemy::takeDamage(int t_amount)
{
	if (t_amount <= 0)
	{
		return;
	}

	if (t_amount >= m_health)
	{
		m_health = 0;
	}
	else
	{
		m_health -= t_amount;
	}
}

int Enemy::health() const
{
	return m_health;
}

bool Enemy::isAlive() const
{
	return m_health > 0;
}