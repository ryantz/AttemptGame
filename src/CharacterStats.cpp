#include "../include/CharacterStats.h"

// Helper functions
std::string  ConvertFactionToString(Faction Faction) {
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
