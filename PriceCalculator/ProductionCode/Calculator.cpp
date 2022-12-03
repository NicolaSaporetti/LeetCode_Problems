#include "Calculator.hpp"
#include "Weapon.hpp"
#include "WeaponCostSummary.hpp"
using namespace std;

WeaponCostSummary Calculator::calculate_cost_weapon(Weapon weapon)
{
    int weapon_modifier = 5;
    int initial_enchantment_cost = weapon.encoumber*weapon.price_base_object*weapon_modifier;
    adjust_initial_enchantment_cost_in_case_is_below_threshold(initial_enchantment_cost,100);
    double final_bonus = weapon.bonus+static_cast<double>(weapon.secondary_bonus)/2;
    WeaponCostSummary costSummary = {static_cast<int>(initial_enchantment_cost*final_bonus)};
    return costSummary;
}

WeaponCostSummary Calculator::calculate_cost_armor(Armor weapon)
{
    int armor_modifier = 3;
    int initial_enchantment_cost = (weapon.encoumber*weapon.price_base_object)/armor_modifier;
    adjust_cost_to_be_base_10(initial_enchantment_cost);
    adjust_initial_enchantment_cost_in_case_is_below_threshold(initial_enchantment_cost,3000);
    int raw_price = initial_enchantment_cost*weapon.bonus;
    WeaponCostSummary costSummary = {raw_price};
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