#include "WeaponCalculator.hpp"
#include "Item.hpp"
#include "ItemSummary.hpp"
using namespace std;

WeaponCalculator::WeaponCalculator() {
    weapon_features[WeaponType::Cerbottana_piccola] = {3,6};
    weapon_features[WeaponType::Cerbottana_grande] = {6,15};
    weapon_features[WeaponType::Bolas] = {5,5};
    weapon_features[WeaponType::Arco_lungo] = {40,30};
    weapon_features[WeaponType::Arco_corto] = {25,20};
    weapon_features[WeaponType::Balestra_pesante] = {50,80};
    weapon_features[WeaponType::Balestra_leggera] = {30,50};
    weapon_features[WeaponType::Fionda] = {2,20};
    weapon_features[WeaponType::Accetta] = {4,30};
    weapon_features[WeaponType::Pugnale] = {7,30};
    weapon_features[WeaponType::Martello_da_lancio] = {5,20};
    weapon_features[WeaponType::Giavellotto] = {1,20};
    weapon_features[WeaponType::Rete] = {10,10};
    weapon_features[WeaponType::Lancia] = {3,30};
    weapon_features[WeaponType::Tridente] = {5,20};
    weapon_features[WeaponType::Manganello] = {5,5};
    weapon_features[WeaponType::Alabarda] = {7,150};
    weapon_features[WeaponType::Lancia_da_cavaliere] = {10,180};
    weapon_features[WeaponType::Picca] = {3,80};
    weapon_features[WeaponType::Ascia_lunga] = {5,120};
    weapon_features[WeaponType::Bastone] = {5,40};
    weapon_features[WeaponType::Spada_a_2_mani] = {15,100};
    weapon_features[WeaponType::Frusta] = {10,100};
    weapon_features[WeaponType::Ascia_da_battaglia] = {7,60};
    weapon_features[WeaponType::Clava] = {3,50};
    weapon_features[WeaponType::Martello_da_guerra] = {5,50};
    weapon_features[WeaponType::Mazza] = {5,30};
    weapon_features[WeaponType::Spada_bastarda] = {15,80};
    weapon_features[WeaponType::Spada] = {10,60};
    weapon_features[WeaponType::Spadino] = {7,30};
}

ItemSummary WeaponCalculator::calculate_cost_weapon(const Weapon& weapon)
{
    ItemSummary summary ={};
    summary.initial_enchantment_cost = calculate_initial_enchantment_cost_weapons(weapon.weaponType);
    summary.enchantment_levels = add_enchantment_levels(weapon);
    double final_bonus = weapon.bonus+static_cast<double>(weapon.secondary_bonus)/2;
    summary.total_cost = static_cast<int>(summary.initial_enchantment_cost*final_bonus);
    return summary;
}

ItemSummary WeaponCalculator::calculate_cost_sword(const Sword& sword)
{
    ItemSummary summary ={};
    summary.initial_enchantment_cost = calculate_initial_enchantment_cost_weapons(sword.weapon.weaponType);
    summary.enchantment_levels = add_enchantment_levels(sword);
    double final_bonus = sword.weapon.bonus+static_cast<double>(sword.weapon.secondary_bonus+sword.third_bonus)/2;
    summary.total_cost = static_cast<int>(summary.initial_enchantment_cost*final_bonus);
    return summary;
}

int WeaponCalculator::calculate_initial_enchantment_cost_weapons(WeaponType weapon_type)
{
    int weapon_modifier = 5;
    int threshold = 100;
    int initial_enchantment_cost = weapon_features[weapon_type].encoumber*weapon_features[weapon_type].price_base_object*weapon_modifier;
    adjust_initial_enchantment_cost_in_case_is_below_threshold(threshold, initial_enchantment_cost);
    return initial_enchantment_cost;
}

void WeaponCalculator::adjust_initial_enchantment_cost_in_case_is_below_threshold(int threshold, int& initial_enchantment_cost)
{
    if(initial_enchantment_cost<threshold) initial_enchantment_cost = threshold;
}

vector<int> WeaponCalculator::add_enchantment_levels(const Weapon& weapon)
{
    vector<int> enchantment_levels;
    enchantment_levels.push_back(weapon.bonus);
    if(weapon.secondary_bonus!=0) enchantment_levels.push_back(weapon.secondary_bonus);
    return enchantment_levels;
}

vector<int> WeaponCalculator::add_enchantment_levels(const Sword& sword)
{
    vector<int> enchantment_levels = add_enchantment_levels(sword.weapon);
    if(sword.third_bonus!=0) enchantment_levels.push_back(sword.third_bonus);
    return enchantment_levels;
}