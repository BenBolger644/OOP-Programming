#include "TrainingBot.h"

TrainingBot::TrainingBot(int t_health) : m_health(t_health)
{

}

int TrainingBot::health() const
{
	return m_health;
}

void TrainingBot::takeDamage(int t_amount)
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

bool TrainingBot::isAlive() const
{
	if (m_health > 0)
		return true;
	else
		return false;
}

void TrainingBot::reset()
{
	m_health = 100;
}