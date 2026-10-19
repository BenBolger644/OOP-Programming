#include <iostream>
#include "Enemy.h"

int main()
{
	std::cout << "Enemy Wave Memory Lab\n";

	std::cout << "Single Dynamic Enemy\n";
	Enemy* pEnemy{ new Enemy{} };
	std::cout << "Starting Health: " << pEnemy->health() << "\n";
	pEnemy->takeDamage(30);
	std::cout << "After 30 damage: " << pEnemy->health() << "\n";
	delete pEnemy;
	pEnemy = nullptr;

	std::cout << "Raw dynamic array\n";
	int enemyCount{ 3 };
	Enemy* pEnemies{ new Enemy[enemyCount] };

	pEnemies[0].takeDamage(25);
	pEnemies[1].takeDamage(100);
	pEnemies[2].takeDamage(60);

	int alive{ 0 };
	int total{ 0 };
	for (int i{ 0 }; i < enemyCount; i++)
	{
		if (pEnemies[i].isAlive())
		{
			++alive;
		}
		total += pEnemies[i].health();
	}

	for (int i{ 0 }; i < enemyCount; ++i)
	{
		std::cout << "Enemy " << i << " health: " << pEnemies[i].health() << "\n";
	}
	std::cout << "Alive enemies: " << alive << "\n";
	std::cout << "Total health: " << total << "\n";

	delete[] pEnemies;
	pEnemies = nullptr;

	return 0;

}