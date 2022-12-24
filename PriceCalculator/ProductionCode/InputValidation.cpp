#include "CommandLine.hpp"
#include "Item.hpp"
#include "ItemSummary.hpp"
#include "Calculator.hpp"
#include <iostream>
using namespace std;

bool InputValidation::verify_bonus_is_correct(int value)
{
    return verify_bonus_is_within_boundaries(1,5,value);
}

bool InputValidation::verify_secondary_bonus_is_correct(int value)
{
    return verify_bonus_is_within_boundaries(0,5,value);
}

bool InputValidation::verify_spell_level_is_correct(int value)
{
    return verify_bonus_is_within_boundaries(1,9,value);
}

bool InputValidation::verify_doses_are_correct(int value)
{
    return verify_bonus_is_within_boundaries(1,3,value);
}

bool InputValidation::verify_number_of_spells(int value)
{
    if(value<1) return false;
    else return true;
}

bool InputValidation::verify_charges_are_correct(int value)
{
    return verify_bonus_is_within_boundaries(1,40,value);
}

bool InputValidation::verify_caster_level_is_correct(int value)
{
    return verify_bonus_is_within_boundaries(9,36,value);
}

bool InputValidation::verify_bonus_is_within_boundaries(int min, int max, int value)
{
    if(value>max || value<min) return false;
    else return true;
}