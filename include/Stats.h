#pragma once
#include <format>
#include "Weapon.h"

enum class Faction {
    SLIME,
    ORC,
    DRAGON,
    HERO,
};

enum class Status {
    ALIVE,
    CRITICAL,
    DEAD,
};

enum class WeaponType {
	SWORD,
	SPEAR,
	SHIELD,
	BOW,
	WOODEN_STICK,
};

namespace CharacterStats {
    struct Slime {
        static constexpr int HEALTH = 10;
        static constexpr int MANA = 0;
        static constexpr int LEVEL = 1;
        static constexpr int EXP_GIVEN = 10;
        static constexpr int BASIC_DAMAGE = 1;
        static constexpr Faction FACTION = Faction::SLIME;
        static constexpr Status STATUS = Status::ALIVE;
    };

    struct Orc {
        static constexpr int HEALTH = 150;
        static constexpr int MANA = 60;
        static constexpr int LEVEL = 10;
        static constexpr int EXP_GIVEN = 100;
        static constexpr int BASIC_DAMAGE = 5;
        static constexpr Faction FACTION = Faction::ORC;
        static constexpr Status STATUS = Status::ALIVE;
    };

    struct Dragon {
        static constexpr int HEALTH = 250;
        static constexpr int MANA = 150;
        static constexpr int LEVEL = 20;
        static constexpr int EXP_GIVEN = 300;
        static constexpr int BASIC_DAMAGE = 8;
        static constexpr Faction FACTION = Faction::DRAGON;
        static constexpr Status STATUS = Status::ALIVE;
    };

    struct Hero {
        static constexpr int HEALTH = 100;
        static constexpr int MANA = 100;
        static constexpr int LEVEL = 1;
        static constexpr int EXP_EARNED = 0;
        static constexpr int BASIC_DAMAGE = 10;
        static constexpr Faction FACTION = Faction::HERO;
        static constexpr Status STATUS = Status::ALIVE;
    };
}

namespace WeaponStats {
    struct Sword {
        static constexpr int DAMAGE = 5;
        static constexpr int DURABILITY = 10;
        static constexpr int WEIGHT = 3;
        static constexpr float ATTACK_SPEED = 0.3f;
        static constexpr WeaponType WEAPON_TYPE = WeaponType::SWORD;
    };
    struct Spear {
        static constexpr int DAMAGE = 5;
        static constexpr int DURABILITY = 10;
        static constexpr int WEIGHT = 3;
        static constexpr float ATTACK_SPEED = 0.3f;
        static constexpr WeaponType WEAPON_TYPE = WeaponType::SPEAR;
    };

    struct Shield {
        static constexpr int DAMAGE = 5;
        static constexpr int DURABILITY = 10;
        static constexpr int WEIGHT = 3;
        static constexpr float ATTACK_SPEED = 0.3f;
        static constexpr WeaponType WEAPON_TYPE = WeaponType::SHIELD;
    };

    struct Bow{
        static constexpr int DAMAGE = 5;
        static constexpr int DURABILITY = 10;
        static constexpr int WEIGHT = 3;
        static constexpr float ATTACK_SPEED = 0.3f;
        static constexpr WeaponType WEAPON_TYPE = WeaponType::BOW;
    };

    struct Wooden_Stick {
        static constexpr int DAMAGE = 5;
        static constexpr int DURABILITY = 10;
        static constexpr int WEIGHT = 3;
        static constexpr float ATTACK_SPEED = 0.3f;
        static constexpr WeaponType WEAPON_TYPE = WeaponType::WOODEN_STICK;
    };
}

std::string ConvertFactionToString(Faction Faction);
std::string ConvertWeaponTypeToString(WeaponType WeaponType);
