#pragma once
#include <iostream>

enum class WeaponTypes {
	SWORD,
	SPEAR,
	SHIELD,
	BOW,
};

class Weapon {
public:
	Weapon();

private:
	int Damage{ 0 };
	int Durability{ 0 };
	int Weight{ 0 };
};