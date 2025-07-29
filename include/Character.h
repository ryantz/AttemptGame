#pragma once

#include <iostream>

enum class Faction {
    SLIME,
    ORC,
    DRAGON,
    HUMAN,
};

class Character {
    Character() = default;
    Character(int Health, int Mana, Faction Faction);

protected:
    int mHealth{ 100 };
    int mMana{ 100 };
    Faction mFaction{ Faction::SLIME };
};

class Orc : Character {
private:
    Faction mFaction = Faction::ORC;
};

class Dragon : Character {
private:
    Faction mFaction = Faction::DRAGON;
};

class Hero : Character {
private:
    Faction mFaction = Faction::HUMAN;
};

void Attack(Character* target);


