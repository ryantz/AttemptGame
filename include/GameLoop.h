#pragma once

#include <iostream>
#include <vector>
#include "Character.h"
#include "Weapon.h"

enum class ControlFlag {
	START,
	END
};

struct CharacterList {
	std::vector<Character> CharacterList; 
};

class GameLoop {
public:
    GameLoop() = default;
	GameLoop(CharacterList CharacterList);

    void Start(ControlFlag CurrentControlFlag);

private:
    ControlFlag mControlFlag;
};

