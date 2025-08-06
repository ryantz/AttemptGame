#pragma once
#include <iostream>
#include "Random.h"


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

	int GetWeaponDamage() {
		return mDamage;
	}

	int GetWeaponDurability() {
		return mDurability;
	}

	int GetWeaponWeight() {
		return mWeight;
	}

	float GetWeaponAttackSpeed() {
		return mAttackSpeed;
	}

	WeaponType GetWeaponType() {
		return mWeaponType;
	}

private:
	int mDamage{ 1 };
	int mDurability{ 1 };
	int mWeight{ 1 };
	float mAttackSpeed{ 0.1f };
	WeaponType mWeaponType{WeaponType::WOODEN_STICK};
};

class Sword : Weapon {
public: 
	Sword();

private:
	bool HeavySlash{Random::Bool(0.1)};
};

class Spear : Weapon {
public:
	Spear();

private:
	int DoubleAttackChance{Random::Integer(0,10)};
};

class Shield : Weapon {
public:
	Shield();

private:
	bool DodgeChance{Random::Bool(0.2)};
};

class Bow : Weapon {
public:
	Bow();

private:
	int CritChance{Random::Integer(0,10)};
};
