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

	return 0;

}