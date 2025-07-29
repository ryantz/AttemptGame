#include <iostream>
#include "../include/Character.h"

// base char
Character::Character(int Health, int Mana, Faction Faction) :
	mHealth{ Health }, mMana{ Mana }, mFaction{ Faction } {
	std::cout << "Custom char created" << std::endl;
}

void Character::OnAttacked() {
	std::cout << "Attacking a slime" << std::endl;
}

void Character::SetHealth(int Health) {
	mHealth = Health;
}

void Character::SetStatus(Status Status) {
	mStatus = Status;
}

void Character::DealDamage(Character* Target, int DamageDealt) {
	if (!Target) {
		std::cout << "Error there is nothing to hit!" << std::endl;
		return;
	}

	int ReducedHealth = Target->GetHealth() - DamageDealt;
	if (ReducedHealth <= 0) {
		Target->SetStatus(Status::DEAD);
	}

	Target->SetHealth(ReducedHealth);
	Target->OnAttacked();
}

// Orc class member functions
Orc::Orc() : Character(150, 30, Faction::ORC) {
	std::cout << "Orc created" << std::endl;
}

void Orc::GoBerserk() {
		SetHealth(50);
		std::cout << "Orc is going berserk! It's health is now: "
			<< GetHealth() << std::endl;
}

void Orc::OnAttacked() {
	std::cout << "Attacking an Orc" << std::endl;
	if (GetHealth() == 10) {
		GoBerserk();
	}
}

// Dragon class member functions
Dragon::Dragon() : Character(300, 150, Faction::DRAGON) {
	std::cout << "Dragon created" << std::endl;
}

void Dragon::DragonRage(Character* Target) {
		DealDamage(Target, 35);
}

void Dragon::OnAttacked() {
	std::cout << "Attacking a Dragon" << std::endl;
	if((GetHealth() % 20) == 0)	{
		std::cout << "Dragon is using DragonRage!" << std::endl;
	}
}

// Hero class member functions
Hero::Hero() : Character(100, 100, Faction::HUMAN) {
	std::cout << "Hero created" << std::endl;
}

void Hero::OnAttacked() {
	std::cout << "Attacking a Hero" << std::endl;
	if (GetHealth() == 50) {
		HerosCalling();
	}
}

void Hero::HerosCalling(Character* Target) {
	SetHealth(150);
	DealDamage(Target, 12);
}


// Generic gameplay functions
