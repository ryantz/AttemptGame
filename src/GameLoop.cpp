#include "../include/GameLoop.h"

GameLoop::GameLoop() {
	std::cout << "Class constructed" << std::endl;
}

void GameLoop::Start() {
	int EnemyChoice;
	int PlayerChoice;
	bool inBattle{true};
	Character* Enemy; // use unique for auto deletion when out of scope

	std::cout << "Game starting..." << std::endl;

	Hero Player; // create the player as a Hero

	std::cout << "Welcome hero, choose an enemy:\n1) Orc\n2) Dragon\n3) Slime" << std::endl;
	std::cin >> EnemyChoice;

	// Player's choice on enemy
	switch (EnemyChoice) {
	case 1: {
		Enemy = new Orc();
		std::cout << "Creating an Orc" << std::endl;
		break;
	}
	case 2: {
		Enemy = new Dragon();
		std::cout << "Creating a Dragon" << std::endl;
		break;
	}
	case 3: {
		Enemy = new Character();
		std::cout << "Creating a Slime" << std::endl;
		break;
	}
	default:
		std::cout << "That was not a choice" << std::endl;
	}

	std::cout << "Battle!" << std::endl;

	while(inBattle) {
		std::cout << "1) Attack\n2) Use Hero's Calling\n3) Run" << std::endl;
		std::cin >> PlayerChoice; 

		switch (PlayerChoice) {
			case 1: {
				Player.DealDamage(Enemy, Player.GetBasicDamage());
				break;
			}
			case 2: {
				Player.HerosCalling(Enemy);
				break;
			}
			case 3: {
				Player.Run(Enemy);
				inBattle = false; // run and break loop
				std::cout << "Ran away successfully..ending game" << std::endl;
				break;
			}
			default:
				std::cout << "That was not an option shown!" << std::endl;
		}
	}
}
