#pragma once
#include "CharacterStats.h"
#include "Weapon.h"

class Character {
public:
    Character() = default; // for slime
    Character(int Health, int Mana, int Level, int BasicDamage, int Exp, Faction Faction, Status mStatus); // for others
    virtual ~Character() = default; // for polymorphism

    virtual void OnAttacked(Character* Attacker);

    int GetHealth() const {
        return mHealth;
    }

    int GetMana() const {
        return mMana;
    }

    Faction GetFaction() const {
        return mFaction;
    }

    Status GetStatus() const {
        return mStatus;
    }

    virtual void SetHealth(int Health);
    virtual void SetStatus(Status Status);
    virtual void DealDamage(Character* Target, int DamageDealt);

protected:
    int mHealth{ 20 };
    int mMana{ 0 };
    int mLevel{ 1 };
    int mExp{ 3 };
    int mBasicDamage;
    Faction mFaction{ Faction::SLIME };
    Status mStatus{ Status::ALIVE };
};

class Orc : public Character {
public:
    Orc();
    
    void OnAttacked(Character* Attacker) override;
    void GoBerserk();
};

class Dragon : public Character {
public:
    Dragon();

    void OnAttacked(Character* Attacker) override;
    void DragonRage(Character* Target);
};

class Hero : public Character {
public:
    Hero();

    void OnAttacked(Character* Attacker) override;
    void HerosCalling(Character* Target);
    void Equip(Weapon* Weapon);
    void Run(Character* Target);
};
