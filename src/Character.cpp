#include <iostream>

class Character {
public:
	void Equip() {
		std::cout << "Weapon Equipped" << std::endl;
	}

	void Attack() {
		std::cout << "Attacked!" << std::endl;
	}

protected:
	int mHealth;
	int mMana;
	int mSpecies;
};

class Orc : Character {};
class Dragon : Character {};
class Hero : Character {};