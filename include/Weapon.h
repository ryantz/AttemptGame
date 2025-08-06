#pragma once
#include <iostream>

enum class WeaponType {
	SWORD,
	SPEAR,
	SHIELD,
	BOW,
	WOODEN_STICK,
};

class Weapon {
public:
	Weapon();

private:
	int Damage{ 1 };
	int Durability{ 1 };
	int Weight{ 1 };
	float AttackSpeed{ 0.1f };
	WeaponType WeaponType{WeaponType::WOODEN_STICK};
};
