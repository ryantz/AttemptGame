#include "../include/Weapon.h"

using SwordStats = WeaponStats::Sword;
using SpearStats = WeaponStats::Spear;
using ShieldStats = WeaponStats::Shield;
using BowStats = WeaponStats::Bow;
using WoodenStickStats = WeaponStats::Wooden_Stick;

Weapon::Weapon(int Damage, int Durability, int Weight, float AttackSpeed, WeaponType WeaponType) :
mDamage{ Damage }, mDurability{ Durability }, mWeight{ Weight }, mAttackSpeed{ AttackSpeed }, mWeaponType{ WeaponType } {
}

Sword::Sword() : Weapon(SwordStats::DAMAGE, SwordStats::DURABILITY, SwordStats::WEIGHT, SwordStats::ATTACK_SPEED, SwordStats::WEAPON_TYPE) {
}

Spear::Spear() : Weapon(SpearStats::DAMAGE, SpearStats::DURABILITY, SpearStats::WEIGHT, SpearStats::ATTACK_SPEED, SpearStats::WEAPON_TYPE) {
}

Shield::Shield() : Weapon(ShieldStats::DAMAGE, ShieldStats::DURABILITY, ShieldStats::WEIGHT, ShieldStats::ATTACK_SPEED, ShieldStats::WEAPON_TYPE) {
}

Bow::Bow() : Weapon(BowStats::DAMAGE, BowStats::DURABILITY, BowStats::WEIGHT, BowStats::ATTACK_SPEED, BowStats::WEAPON_TYPE) {
}
