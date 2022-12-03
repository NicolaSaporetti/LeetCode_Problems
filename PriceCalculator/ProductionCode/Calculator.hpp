#ifndef Calculator_HPP
#define Calculator_HPP

#include "Item.hpp"
#include "ItemSummary.hpp"
using namespace std;

class Calculator {
public:
    Calculator() {}
    ItemSummary calculate_cost_weapon(Weapon weapon);
    ItemSummary calculate_cost_armor(Armor armor);
    ItemSummary calculate_cost_potion(Potion potion);
    ItemSummary calculate_cost_scroll(Scroll scroll);
    ItemSummary calculate_cost_wand(Wand wand);

private:
    void adjust_initial_enchantment_cost_in_case_is_below_threshold(int& initial_enchantment_cost, int threshold);
    void adjust_cost_to_be_base_10(int& modified_enchantment_cost);
};
#endif