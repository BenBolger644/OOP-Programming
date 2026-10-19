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