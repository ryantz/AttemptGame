#include "../include/CharacterStats.h"

// Helper functions
std::string  ConvertFactionToString(const Faction Faction) {
    switch (Faction) {
    case Faction::SLIME: 
        return "Slime";
    case Faction::ORC:
        return "Orc";
    case Faction::DRAGON:
        return "Dragon";
    case Faction::HERO:
        return "Hero";
    default:
        return "Unknown Faction";
    }
}

std::string ConvertWeaponTypeToString(const WeaponType WeaponType) {
    switch (WeaponType) {
        case WeaponType::SWORD:
            return "Sword";
        case WeaponType::SPEAR:
            return "Spear";
        case WeaponType::SHIELD:
            return "Shield";
        case WeaponType::BOW:
            return "Bow";
        case WeaponType::WOODEN_STICK:
            return "Wooden stick";
        default:
            return "Unknown weapon";

    }
}
