#include "../include/Character.h"

using OrcStats = CharacterStats::Orc;
using DragonStats = CharacterStats::Dragon;
using HeroStats = CharacterStats::Hero;

// base char = slime
Character::Character(int Health, int Mana, int Level, int Exp, int BasicDamage, Faction Faction, Status Status) :
	mHealth{ Health }, mMana{ Mana }, mLevel{ Level }, mExp{ Exp }, mBasicDamage{ BasicDamage }, mFaction { Faction }, mStatus{ Status } {
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
	} 
	else if (ReducedHealth <= 20) {
		Target->SetStatus(Status::CRITICAL);
	}
	else {
		Target->SetStatus(Status::ALIVE);
	}

	Target->SetHealth(ReducedHealth);
	Target->OnAttacked(this);

	std::cout << ConvertFactionToString(Target->GetFaction()) << " 's Health is now "
		<< Target->GetHealth() << std::endl;
}

// Orc class member functions
Orc::Orc() : Character(OrcStats::HEALTH, OrcStats::MANA, OrcStats::LEVEL, OrcStats::BASIC_DAMAGE, OrcStats::EXP_GIVEN, OrcStats::FACTION, OrcStats::STATUS) {
	std::cout << "Orc created" << std::endl;
}

void Orc::GoBerserk() {
		SetHealth(50);
		std::cout << "Orc is going berserk! It's health is now: "
			<< GetHealth() << std::endl;
}

void Orc::OnAttacked(Character* Attacker) {
	std::cout << ConvertFactionToString(Attacker->GetFaction())
		<< " is attacking an Orc" << std::endl;

	if (GetHealth() == 10) {
		GoBerserk();
	}
}

// Dragon class member functions
Dragon::Dragon() : Character(DragonStats::HEALTH, DragonStats::MANA, DragonStats::LEVEL, DragonStats::BASIC_DAMAGE, DragonStats::EXP_GIVEN, DragonStats::FACTION, DragonStats::STATUS) {
	std::cout << "Dragon created" << std::endl;
}

void Dragon::DragonRage(Character* Target) {
		DealDamage(Target, 35);
}

void Dragon::OnAttacked(Character* Attacker) {
	std::cout << ConvertFactionToString(Attacker->GetFaction()) 
		<< " is attacking a Dragon" << std::endl;

	if((GetHealth() % 20) == 0)	{
		DragonRage(Attacker);
		std::cout << "Dragon is using DragonRage!" << std::endl;
	}
}

// Hero class member functions
Hero::Hero() : Character(HeroStats::HEALTH, HeroStats::MANA, HeroStats::LEVEL, HeroStats::BASIC_DAMAGE, HeroStats::EXP_EARNED, HeroStats::FACTION, HeroStats::STATUS) {
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
	std::cout << "HERO'S CALLING!" << std::endl;

	SetHealth(150);
	DealDamage(Target, 13);
}

void Hero::Equip(Weapon* Weapon) {

}

void Hero::Run(Character* Target) {
	std::cout << "You ran away from the " << ConvertFactionToString(Target->GetFaction()) << std::endl;
}
