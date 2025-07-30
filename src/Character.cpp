#include <iostream>
#include "../include/Character.h"

// Helper functions
std::string  ConvertFactionToString(Faction Faction) {
    switch (Faction) {
    case Faction::SLIME: 
        return "Slime";
    case Faction::ORC:
        return "Orc";
    case Faction::DRAGON:
        return "Dragon";
    case Faction::HUMAN:
        return "Human";
    default:
        return "Unknown Faction";
    }
}

// base char
Character::Character(int Health, int Mana, Faction Faction) :
	mHealth{ Health }, mMana{ Mana }, mFaction{ Faction } {
	std::cout << "Custom char created" << std::endl;
}

void Character::OnAttacked(Character* Attacker) {
	std::cout << ConvertFactionToString(Attacker->GetFaction()) 
		<< " is Attacking a slime" << std::endl;
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
	} else if (ReducedHealth <= 20) {
		Target->SetStatus(Status::CRITICAL);
	} else {
		Target->SetStatus(Status::ALIVE);
	}

	Target->SetHealth(ReducedHealth);
	Target->OnAttacked(Target);
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

void Orc::OnAttacked(Character* Target) {
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

void Dragon::OnAttacked(Character* Target) {
	std::cout << "Attacking a Dragon" << std::endl;
	if((GetHealth() % 20) == 0)	{
		DragonRage(Target);
		std::cout << "Dragon is using DragonRage!" << std::endl;
	}
}

// Hero class member functions
Hero::Hero() : Character(100, 100, Faction::HUMAN) {
	std::cout << "Hero created" << std::endl;
}

void Hero::OnAttacked(Character* Target) {
	std::cout << "Attacking a Hero" << std::endl;
	if (GetHealth() == 50) {
		HerosCalling(Target);
	}
}

void Hero::HerosCalling(Character* Target) {
	SetHealth(150);
	DealDamage(Target, 12);
}
