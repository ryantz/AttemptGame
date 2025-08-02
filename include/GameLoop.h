#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include "Character.h"
#include "Weapon.h"

class GameLoop {
public:
    GameLoop();
	void Start();

private:
	std::unique_ptr<Hero> Player;
	std::unique_ptr<Character> Enemy;
};

