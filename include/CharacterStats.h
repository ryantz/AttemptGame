#include <iostream>

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

namespace CharacterStats {
    struct Slime {
        static constexpr int HEALTH = 10;
        static constexpr int MANA = 0;
        static constexpr int LEVEL = 1;
        static constexpr int EXP = 10;
        static constexpr int BASIC_DAMAGE = 1;
        static constexpr Faction FACTION = Faction::SLIME;
        static constexpr Status STATUS = Status::ALIVE;
    };

    struct Orc {
        static constexpr int HEALTH = 150;
        static constexpr int MANA = 60;
        static constexpr int LEVEL = 10;
        static constexpr int EXP = 100;
        static constexpr int BASIC_DAMAGE = 6;
        static constexpr Faction FACTION = Faction::ORC;
        static constexpr Status STATUS = Status::ALIVE;
};

    struct Dragon {
        static constexpr int HEALTH = 250;
        static constexpr int MANA = 150;
        static constexpr int LEVEL = 20;
        static constexpr int EXP = 300;
        static constexpr int BASIC_DAMAGE = 10;
        static constexpr Faction FACTION = Faction::DRAGON;
        static constexpr Status STATUS = Status::ALIVE;
};

    struct Hero {
        static constexpr int HEALTH = 100;
        static constexpr int MANA = 100;
        static constexpr int LEVEL = 1;
        static constexpr int EXP = 0;
        static constexpr int BASIC_DAMAGE = 4;
        static constexpr Faction FACTION = Faction::HERO;
        static constexpr Status STATUS = Status::ALIVE;
};
}

std::string  ConvertFactionToString(Faction Faction);