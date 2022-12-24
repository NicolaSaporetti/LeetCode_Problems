#ifndef CommandLine_HPP
#define CommandLine_HPP

#include "ItemSummary.hpp"
#include "Item.hpp"
#include "ObjectCreationSummary.hpp"
#include "Calculator.hpp"
#include "ObjectCreator.hpp"
#include "InputValidation.hpp"
using namespace std;

class CommandLine {
public:
    CommandLine() {}
    ItemSummary compute_cost();
    ObjectCreationSummary compute_details_object_creation(const ItemSummary& item);
private:
    int fill_primary_bonus();
    int fill_secondary_bonus();
    int fill_third_bonus();
    int fill_second_bonus();
    int fill_doses();
    vector<int> fill_spells();
    int fill_spell_level();
    int fill_number_of_spells();
    int fill_charges();
    int fill_int();
    RechargeType get_recharge_type();
    WeaponType get_sword_type();
    WeaponType get_various_weapon_type();
    ArmorType get_armor_type();
    int fill_caster_levels();

    Calculator calculator;
    ObjectCreator objectCreator;
    InputValidation inputValidation;
};
#endif