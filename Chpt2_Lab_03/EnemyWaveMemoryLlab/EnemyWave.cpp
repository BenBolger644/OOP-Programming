#include "EnemyWave.h"
#include "Enemy.h"

EnemyWave::EnemyWave(int t_count)
{
	if (t_count > 0 && t_count <= MAX_ENEMIES)
	{
		m_count = t_count;
		m_enemies = new Enemy[m_count];
	}
}
EnemyWave::~EnemyWave()
{
	delete[] m_enemies;
}

int EnemyWave::count() const
{
	return m_count;
}

bool EnemyWave::damageEnemy(int t_index, int t_amount)
{
	if (t_index < 0 || t_index >= m_count)
	{
		return false;
	}

	m_enemies[t_index].takeDamage(t_amount);
	return true;
}

int EnemyWave::healthAt(int t_index) const
{
	if (t_index < 0 || t_index >= m_count)
	{
		return -1;
	}

	return m_enemies[t_index].health();
}

int EnemyWave::aliveCount() const
{
	int alive{ 0 };

	for (int i{ 0 }; i < m_count; ++i)
	{
		if (m_enemies[i].isAlive())
		{
			++alive;
		}
	}

	return alive;
}

int EnemyWave::totalHealth() const
{
	int total{ 0 };

	for (int i{ 0 }; i < m_count; ++i)
	{
		total += m_enemies[i].health();
	}

	return total;
}