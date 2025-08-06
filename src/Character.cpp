#include "../include/Character.h"
#include <format>

using OrcStats = CharacterStats::Orc;
using DragonStats = CharacterStats::Dragon;
using HeroStats = CharacterStats::Hero;

// base char = slime
Character::Character(int Health, int Mana, int Level, int BasicDamage, int Exp, Faction Faction, Status Status) :
	mHealth{ Health }, mMana{ Mana }, mLevel{ Level }, mBasicDamage{ BasicDamage }, mExp{ Exp }, mFaction { Faction }, mStatus{ Status } {
}

void Character::OnAttacked(Character* Attacker) {
	std::cout << ConvertFactionToString(Attacker->GetFaction()) 
		<< " is Attacking a slime" << std::endl;
}

void Character::SetHealth(int Health) {
	mHealth = Health;
}

void Character::SetMana(int Mana) {
	mMana = Mana;
}

void Character::SetStatus(Status Status) {
	mStatus = Status;
}

// TODO add in mana functionality
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
	
	std::cout << "\n" <<  ConvertFactionToString(Target->GetFaction()) << " 's Health is now "
		<< Target->GetHealth() << std::endl;
}

// Orc class member functions
Orc::Orc() : Character(OrcStats::HEALTH, OrcStats::MANA, OrcStats::LEVEL, OrcStats::BASIC_DAMAGE , OrcStats::EXP_GIVEN, OrcStats::FACTION, OrcStats::STATUS) {
}

void Orc::GoBerserk(int ManaRequired) {
	int CurrentMana = this->GetMana();

	if (CurrentMana >= ManaRequired) {
		SetHealth(50);
		CurrentMana -= ManaRequired;
		SetMana(CurrentMana);
		std::cout << 
			std::format("Orc is going Berserk!\nOrc HP is now: {0}\nMana{1}", GetHealth(), GetMana())
				<< std::endl;
	}
	else {
		std::cout << "Orc cannot use Berserk (out of mana)" << std::endl;
	}
}

void Orc::OnAttacked(Character* Attacker) {
	//std::cout << ConvertFactionToString(Attacker->GetFaction())
	//	<< " is attacking an Orc" << std::endl;

	if (GetHealth() <= 20) {
		GoBerserk(60);
	}
}

// Dragon class member functions
Dragon::Dragon() : Character(DragonStats::HEALTH, DragonStats::MANA, DragonStats::LEVEL, DragonStats::BASIC_DAMAGE, DragonStats::EXP_GIVEN, DragonStats::FACTION, DragonStats::STATUS) {
}

void Dragon::DragonRage(Character* Target) {
		DealDamage(Target, 30);
		std::cout << "Dragon is using DragonRage!" << std::endl;
}

void Dragon::OnAttacked(Character* Attacker) {
	//std::cout << ConvertFactionToString(Attacker->GetFaction()) 
	//	<< " is attacking a Dragon" << std::endl;

	if((GetHealth() % 20) == 0)	{
		DragonRage(Attacker);
	}
}

// Hero class member functions
Hero::Hero() : Character(HeroStats::HEALTH, HeroStats::MANA, HeroStats::LEVEL, HeroStats::BASIC_DAMAGE, HeroStats::EXP_EARNED , HeroStats::FACTION, HeroStats::STATUS) {
}

void Hero::OnAttacked(Character* Attacker) {
	//std::cout << ConvertFactionToString(Attacker->GetFaction())
	//	<< " is attacking a Hero" << std::endl;

	if (GetHealth() == 50) {
		HerosCalling(Attacker, 100);
	}
}

void Hero::HerosCalling(Character* Target, int ManaRequired) {
	int CurrentMana = this->GetMana();

	if (CurrentMana >= ManaRequired) {
		SetHealth(150);
		DealDamage(Target, 15);
		CurrentMana -= ManaRequired;
		SetMana(CurrentMana);
		std::cout << "HERO'S CALLING!" << std::endl;
	}
	else {
		std::cout << "You cannot use HerosCalling (out of mana)" << std::endl;
	}
}

void Hero::Equip(Weapon* Weapon) {
	std::cout << std::format("Character is now using {}" , ConvertWeaponTypeToString(Weapon->GetWeaponType())) << std::endl;
}

void Hero::Run(Character* Target) {
	std::cout << "You ran away from the " << ConvertFactionToString(Target->GetFaction()) << std::endl;
}
