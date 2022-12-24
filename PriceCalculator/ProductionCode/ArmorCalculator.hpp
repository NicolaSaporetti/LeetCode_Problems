#ifndef ArmorCalculator_HPP
#define ArmorCalculator_HPP

#include "Item.hpp"
#include "ItemSummary.hpp"
#include <unordered_map>
using namespace std;

class ArmorCalculator {
public:
    ArmorCalculator();
    ItemSummary calculate_cost_armor(const Armor& armor);

private:
    void adjust_initial_enchantment_cost_in_case_is_below_threshold(int threshold, int& initial_enchantment_cost);
    void adjust_cost_to_be_base_10(int& initial_enchantment_cost);
    vector<int> add_enchantment_levels(const Armor& weapon);

    unordered_map<ArmorType,ArmorAndWeapon> armor_features;
};
#endif