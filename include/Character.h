#pragma once

#include <iostream>

enum class Faction {
    SLIME,
    ORC,
    DRAGON,
    HUMAN,
};

enum class Status {
    ALIVE,
    CRITICAL,
    DEAD,
};

std::string  ConvertFactionToString(Faction Faction);

class Character {
public:
    Character() = default;
    Character(int Health, int Mana, Faction Faction);
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
    Faction mFaction{ Faction::SLIME };
    Status mStatus{ Status::ALIVE };
};

class Orc : public Character {
public:
    Orc();
    
    void OnAttacked(Character* Target) override;
    void GoBerserk();
};

class Dragon : public Character {
public:
    Dragon();

    void OnAttacked(Character* Target) override;
    void DragonRage(Character* Target);
};

class Hero : public Character {
public:
    Hero();

    void OnAttacked(Character* Target) override;
    void HerosCalling(Character* Target);
};
