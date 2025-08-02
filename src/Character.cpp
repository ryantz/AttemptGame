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

void Attack(Character* Target) {
	
}

// base char
Character::Character(int Health, int Mana, int Level, int Exp, Faction Faction, Status Status) :
	mHealth{ Health }, mMana{ Mana }, mLevel{ Level }, mExp{ Exp }, mFaction{ Faction }, mStatus{Status} {
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
	Target->OnAttacked(this);
}

// Orc class member functions
Orc::Orc() : Character(150, 30, 10, 300, Faction::ORC, Status::ALIVE) {
	std::cout << "Orc created" << std::endl;
}

void Orc::GoBerserk() {
		SetHealth(50);
		std::cout << "Orc is going berserk! It's health is now: "
			<< GetHealth() << std::endl;
}

void Orc::OnAttacked(Character* Attacker) {
	std::cout << ConvertFactionToString(Attacker->GetFaction())
		<< "is attacking an Orc" << std::endl;

	if (GetHealth() == 10) {
		GoBerserk();
	}
}

// Dragon class member functions
Dragon::Dragon() : Character(300, 150, 20, 450, Faction::DRAGON, Status::ALIVE) {
	std::cout << "Dragon created" << std::endl;
}

void Dragon::DragonRage(Character* Target) {
		DealDamage(Target, 35);
}

void Dragon::OnAttacked(Character* Attacker) {
	std::cout << ConvertFactionToString(Attacker->GetFaction()) 
		<< "is attacking a Dragon" << std::endl;

	if((GetHealth() % 20) == 0)	{
		DragonRage(Attacker);
		std::cout << "Dragon is using DragonRage!" << std::endl;
	}
}

// Hero class member functions
Hero::Hero() : Character(100, 100, 1, 0, Faction::HUMAN, Status::ALIVE) {
	std::cout << "Hero created" << std::endl;
}

void Hero::OnAttacked(Character* Attacker) {
	std::cout << ConvertFactionToString(Attacker->GetFaction())
		<< " is attacking a Hero" << std::endl;

	if (GetHealth() == 50) {
		HerosCalling(Attacker);
	}
}

void Hero::HerosCalling(Character* Target) {
	SetHealth(150);
	DealDamage(Target, 12);
}
