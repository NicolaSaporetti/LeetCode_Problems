#include "Calculator.hpp"
#include "WeaponCalculator.hpp"
#include "ArmorCalculator.hpp"
#include "Item.hpp"
#include "ItemSummary.hpp"
#include <numeric>
using namespace std;

ItemSummary Calculator::calculate_cost_weapon(const Weapon& weapon)
{
    return weapon_creator.calculate_cost_weapon(weapon);
}

ItemSummary Calculator::calculate_cost_sword(const Sword& sword)
{
    return weapon_creator.calculate_cost_sword(sword);
}

ItemSummary Calculator::calculate_cost_armor(const Armor& armor)
{
    return armor_creator.calculate_cost_armor(armor);
}

ItemSummary Calculator::calculate_cost_item_with_charges(const ItemWithCharges& item_with_charges)
{
    ItemSummary summary = {};
    double rechargable_item_multiplier = compute_charges_item_multiplier(item_with_charges.recharge_type);
    int charges = item_with_charges.charges+compute_additional_chages(item_with_charges.recharge_type);
    const int spell_level_multiplier = 1000;
    int sum_spell_levels = accumulate(item_with_charges.spells_level.begin(), item_with_charges.spells_level.end(), 0);
    summary.initial_enchantment_cost = sum_spell_levels*spell_level_multiplier*rechargable_item_multiplier;
    summary.enchantment_levels = item_with_charges.spells_level;
    summary.charge_cost = summary.initial_enchantment_cost/10;
    summary.total_cost = summary.initial_enchantment_cost+charges*summary.charge_cost;
    set_cost_for_charges_to_none_if_non_rechargeable_or_periodical(item_with_charges.recharge_type,summary.charge_cost);
    return summary;
}

double Calculator::compute_charges_item_multiplier(RechargeType recharge_type)
{
    double rechargable_item_multiplier = 0.0;
    switch (recharge_type)
    {
        case RechargeType::Recheargeable :
            rechargable_item_multiplier = 1.0;
        break;
        case RechargeType::Non_recheargeable :
            rechargable_item_multiplier = 0.8;
        break;
        case RechargeType::Hourly :
            rechargable_item_multiplier = 0.80;
        break;
        case RechargeType::Daily :
            rechargable_item_multiplier = 0.75;
        break;
        case RechargeType::Weekly :
            rechargable_item_multiplier = 0.70;
        break;
        case RechargeType::Montly :
            rechargable_item_multiplier = 0.65;
        break;
    }
    return rechargable_item_multiplier;
}

int Calculator::compute_additional_chages(RechargeType recharge_type)
{
    int additional_charges = 0;
    switch (recharge_type)
    {
        case RechargeType::Hourly :
        case RechargeType::Daily :
        case RechargeType::Weekly :
        case RechargeType::Montly :
            additional_charges=30;
        break;
    }
    return additional_charges;
}

void Calculator::set_cost_for_charges_to_none_if_non_rechargeable_or_periodical(RechargeType recharge_type, int& charges)
{
    switch (recharge_type)
    {
        case RechargeType::Non_recheargeable :
        case RechargeType::Hourly :
        case RechargeType::Daily :
        case RechargeType::Weekly :
        case RechargeType::Montly :
            charges=0;
        break;
    }
}

ItemSummary Calculator::calculate_cost_permanent_item(const PermanentItem& item)
{
    ItemSummary summary = {};
    int spell_level_multiplier = 1000;
    summary.initial_enchantment_cost = item.spell_level*spell_level_multiplier;
    summary.enchantment_levels = {item.spell_level};
    int permanency_cost = summary.initial_enchantment_cost*5;
    summary.total_cost = summary.initial_enchantment_cost+permanency_cost;
    return summary;
}