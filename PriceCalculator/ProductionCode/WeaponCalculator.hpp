#ifndef WeaponCreator_HPP
#define WeaponCreator_HPP

#include "Item.hpp"
#include "ItemSummary.hpp"
#include <unordered_map>
using namespace std;

class WeaponCalculator {
public:
    WeaponCalculator();
    ItemSummary calculate_cost_weapon(const Weapon& weapon);
    ItemSummary calculate_cost_sword(const Sword& sword);

private:
    int calculate_initial_enchantment_cost_weapons(WeaponType weapon);
    void adjust_initial_enchantment_cost_in_case_is_below_threshold(int threshold, int& initial_enchantment_cost);
    vector<int> add_enchantment_levels(const Weapon& weapon);
    vector<int> add_enchantment_levels(const Sword& weapon);

    unordered_map<WeaponType,ArmorAndWeapon> weapon_features;
};
#endif