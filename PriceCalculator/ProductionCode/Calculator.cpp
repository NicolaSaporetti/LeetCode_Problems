#include "Calculator.hpp"
#include "Item.hpp"
#include "ItemSummary.hpp"
using namespace std;

ItemSummary Calculator::calculate_cost_weapon(Weapon weapon)
{
    int weapon_modifier = 5;
    int initial_enchantment_cost = weapon.encoumber*weapon.price_base_object*weapon_modifier;
    adjust_initial_enchantment_cost_in_case_is_below_threshold(initial_enchantment_cost,100);
    double final_bonus = weapon.bonus+static_cast<double>(weapon.secondary_bonus)/2;
    ItemSummary costSummary = {static_cast<int>(initial_enchantment_cost*final_bonus)};
    return costSummary;
}

ItemSummary Calculator::calculate_cost_armor(Armor armor)
{
    int armor_modifier = 3;
    int initial_enchantment_cost = (armor.encoumber*armor.price_base_object)/armor_modifier;
    adjust_cost_to_be_base_10(initial_enchantment_cost);
    adjust_initial_enchantment_cost_in_case_is_below_threshold(initial_enchantment_cost,3000);
    int raw_price = initial_enchantment_cost*armor.bonus;
    ItemSummary costSummary = {raw_price};
    return costSummary;
}

void Calculator::adjust_initial_enchantment_cost_in_case_is_below_threshold(int& initial_enchantment_cost, int threshold)
{
    if(initial_enchantment_cost<threshold) initial_enchantment_cost = threshold;
}

void Calculator::adjust_cost_to_be_base_10(int& modified_enchantment_cost)
{
    if(modified_enchantment_cost%10!=0) modified_enchantment_cost+=10-(modified_enchantment_cost%10);
}

ItemSummary Calculator::calculate_cost_potion(Potion potion)
{
    double non_rechargable_item_multiplier = 0.8;
    int spell_level_multiplier = 1000;
    int initial_enchantment_cost = potion.spell_level*spell_level_multiplier;
    int doses_cost = (initial_enchantment_cost/10)*potion.doses;
    ItemSummary costSummary = {static_cast<int>((initial_enchantment_cost+doses_cost)*non_rechargable_item_multiplier)};
    return costSummary;
}

ItemSummary Calculator::calculate_cost_scroll(Scroll scroll)
{
    double non_rechargable_item_multiplier = 0.8;
    int spell_level_multiplier = 1000;
    ItemSummary costSummary = {static_cast<int>((scroll.spell_levels*spell_level_multiplier)*non_rechargable_item_multiplier)};
    return costSummary;
}

ItemSummary Calculator::calculate_cost_wand(Wand wand)
{
    double non_rechargable_item_multiplier = 0.8;
    int spell_level_multiplier = 1000;
    int initial_enchantment_cost = wand.spell_level*spell_level_multiplier;
    int charges_cost = (initial_enchantment_cost/10)*wand.charges;
    int cost = initial_enchantment_cost+charges_cost;
    if(!wand.rechargeable) cost*=non_rechargable_item_multiplier;
    ItemSummary costSummary = {cost};
    return costSummary;
}
