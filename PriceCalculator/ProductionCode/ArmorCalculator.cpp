#include "ArmorCalculator.hpp"
#include "Item.hpp"
#include "ItemSummary.hpp"
using namespace std;

ArmorCalculator::ArmorCalculator() {
    armor_features[ArmorType::Cuoio] = {20,200};
    armor_features[ArmorType::Maglia] = {40,400};
    armor_features[ArmorType::Piastre] = {60,500};
    armor_features[ArmorType::Scudo] = {10,100};
    armor_features[ArmorType::Scudo_appuntito] = {15,20};
    armor_features[ArmorType::Scudo_laminato] = {65,70};
    armor_features[ArmorType::Scudo_lanceolato] = {200,185};
    armor_features[ArmorType::Scudo_dentato] = {200,275};
    armor_features[ArmorType::Bardatura_per_cavalli] = {150,600};
}

ItemSummary ArmorCalculator::calculate_cost_armor(const Armor& armor)
{
    ItemSummary summary ={};
    int armor_modifier = 3;
    int threshold = 3000;
    summary.initial_enchantment_cost = (armor_features[armor.armorType].encoumber*armor_features[armor.armorType].price_base_object)/armor_modifier;
    adjust_cost_to_be_base_10(summary.initial_enchantment_cost);
    adjust_initial_enchantment_cost_in_case_is_below_threshold(threshold, summary.initial_enchantment_cost);
    summary.enchantment_levels = add_enchantment_levels(armor);
    summary.total_cost = summary.initial_enchantment_cost*armor.bonus;
    return summary;
}

void ArmorCalculator::adjust_initial_enchantment_cost_in_case_is_below_threshold(int threshold, int& initial_enchantment_cost)
{
    if(initial_enchantment_cost<threshold) initial_enchantment_cost = threshold;
}

void ArmorCalculator::adjust_cost_to_be_base_10(int& initial_enchantment_cost)
{
    if(initial_enchantment_cost%10!=0) initial_enchantment_cost+=10-(initial_enchantment_cost%10);
}

vector<int> ArmorCalculator::add_enchantment_levels(const Armor& weapon)
{
    return {weapon.bonus};
}
