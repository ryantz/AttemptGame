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
    Weapon* WeaponChoice(int Choice, Hero* &Player);
    Character* EnemyChoiceLoop(int Choice, Character* Enemy);
};
