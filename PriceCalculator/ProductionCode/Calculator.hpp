#ifndef Calculator_HPP
#define Calculator_HPP

#include "Item.hpp"
#include "ItemSummary.hpp"
#include "WeaponCalculator.hpp"
#include "ArmorCalculator.hpp"
using namespace std;

class Calculator {
public:
    ItemSummary calculate_cost_weapon(const Weapon& weapon);
    ItemSummary calculate_cost_sword(const Sword& sword);
    ItemSummary calculate_cost_armor(const Armor& armor);
    ItemSummary calculate_cost_item_with_charges(const ItemWithCharges& wand);
    ItemSummary calculate_cost_permanent_item(const PermanentItem& item);

private:
    double compute_charges_item_multiplier(RechargeType recharge_type);
    int compute_additional_chages(RechargeType recharge_type);
    void set_cost_for_charges_to_none_if_non_rechargeable_or_periodical(RechargeType recharge_type, int& charges);

    WeaponCalculator weapon_creator;
    ArmorCalculator armor_creator;
};
#endif