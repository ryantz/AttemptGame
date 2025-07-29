#include <iostream>
#include "../include/Character.h"

Character::Character(int Health, int Mana, Faction Faction) :
	mHealth{ Health }, mMana{ Mana }, mFaction{ Faction } {
	std::cout << "Custom char created" << std::endl;
}

void Attack(Character* target) {
	std::cout << "attack" << std::endl;
}
