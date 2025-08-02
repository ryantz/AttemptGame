#include "../include/GameLoop.h"

GameLoop::GameLoop(CharacterList CharacterList) {
	std::cout << "Game starting.." << std::endl;
}

void GameLoop::Start(ControlFlag CurrentControlFlag) {
	while(CurrentControlFlag == ControlFlag::START){ 
		std::cout << "Looping" << std::endl;
	}
}
