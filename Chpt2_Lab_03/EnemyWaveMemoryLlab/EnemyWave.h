#ifndef ENEMY_WAVE_H
#define ENEMY_WAVE_H

class Enemy;

class EnemyWave
{
public:
	explicit EnemyWave(int t_count);
	~EnemyWave();

	EnemyWave(EnemyWave const&) = delete;
	EnemyWave& operator=(EnemyWave const&) = delete;

	int count() const;
	bool damageEnemy(int t_index, int t_amount);
	int healthAt(int t_index) const;
	int aliveCount() const;
	int totalHealth() const;

private:
	static constexpr int MAX_ENEMIES{ 5 };

	int m_count{ 0 };
	Enemy* m_enemies{ nullptr };
};

#endif
