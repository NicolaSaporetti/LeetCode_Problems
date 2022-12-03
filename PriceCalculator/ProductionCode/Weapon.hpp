#ifndef Weapon_HPP
#define Weapon_HPP
using namespace std;

typedef struct Weapon {
    int price_base_object;
    int encoumber;
    int bonus;
    int secondary_bonus;
} Weapon;

typedef struct Armor {
    int price_base_object;
    int encoumber;
    int bonus;
} Armor;

typedef struct Potion {
    int spell_level;
    int doses;
} Potion;

typedef struct Scroll {
    int spell_levels;
} Scroll;

#endif