#include "../include/GameLoop.h"

GameLoop::GameLoop() {
	std::cout << "Class constructed" << std::endl;
}

void GameLoop::Start() {
	int EnemyChoice;
	Character* Enemy{ nullptr };
	
	std::cout << "Game starting..." << std::endl;

	Hero Player; // create the player as a Hero

	std::cout << "Welcome hero, choose an enemy:\n1) Orc\n2) Dragon\n3) Slime\n" << std::endl;
	std::cin >> EnemyChoice;
	std::cout << "\n";

	// Player's choice on enemy
	switch (EnemyChoice) {
	case 1: {
		Enemy = new Orc();
		std::cout << "Creating an Orc..\n" << std::endl;
		break;
	}
	case 2: {
		Enemy = new Dragon();
		std::cout << "Creating a Dragon..\n" << std::endl;
		break;
	}
	case 3: {
		Enemy = new Character();
		std::cout << "Creating a Slime..\n" << std::endl;
		break;
	}
	default:
		std::cout << "That was not a choice" << std::endl;
	}

	if(Enemy != nullptr){
		bool inBattle{true};
		std::cout << "Battle!" << std::endl;

		while(inBattle) {
			int PlayerChoice;
			std::cout << "1) Attack\n2) Run\n" << std::endl;
			std::cin >> PlayerChoice;
			std::cout << "\n";

			switch (PlayerChoice) {
				case 1: {
					std::cout << "\n=====================================\n" << std::endl;
					Player.DealDamage(Enemy, Player.GetBasicDamage());
					std::cout << "\n=====================================\n" << std::endl;
					Enemy->DealDamage(&Player, Enemy->GetBasicDamage());
					std::cout << "\n=====================================\n" << std::endl;
					
					if (Enemy->GetHealth() <= 0 || Player.GetHealth() <= 0) {
						inBattle = false;
					}
					
					break;
				}
				case 2: {
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
	delete Enemy;
}

