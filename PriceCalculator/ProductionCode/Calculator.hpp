#ifndef Calculator_HPP
#define Calculator_HPP

#include "Weapon.hpp"
#include "WeaponCostSummary.hpp"
using namespace std;

class Calculator {
public:
    Calculator() {}
    WeaponCostSummary calculate_cost_weapon(Weapon weapon);
    WeaponCostSummary calculate_cost_armor(Armor weapon);

private:
    void adjust_initial_enchantment_cost_in_case_is_below_threshold(int& initial_enchantment_cost, int threshold);
    void adjust_cost_to_be_base_10(int& modified_enchantment_cost);
};
#endif