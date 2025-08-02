#include "../include/GameLoop.h"

GameLoop::GameLoop() {
	std::cout << "Class constructed" << std::endl;
}

void GameLoop::Start() {
	int choice;
	Character* EnemyChoice; // use unique for auto deletion when out of scope

	std::cout << "Game starting..." << std::endl;

	Hero Player;

	std::cout << "Welcome hero, choose an enemy:\n1) Orc\n2) Dragon\n3) Slime" << std::endl;
	std::cin >> choice;

	switch (choice) {
	case 1: {
		EnemyChoice = new Orc();
		std::cout << "Creating an Orc" << std::endl;
		break;
	}
	case 2: {
		EnemyChoice = new Dragon();
		std::cout << "Creating a Dragon" << std::endl;
		break;
	}
	case 3: {
		EnemyChoice = new Character();
		std::cout << "Creating a Slime" << std::endl;
		break;
	}
	default:
		std::cout << "That was not a choice" << std::endl;
	}

	std::cout << "Battle!" << std::endl;
	Player.DealDamage(EnemyChoice, 100);
}
