#ifndef InputValidation_HPP
#define InputValidation_HPP
using namespace std;

class InputValidation {
public:
    InputValidation() {}
    bool verify_bonus_is_correct(int value);
    bool verify_secondary_bonus_is_correct(int value);
    bool verify_spell_level_is_correct(int value);
    bool verify_doses_are_correct(int value);
    bool verify_number_of_spells(int value);
    bool verify_charges_are_correct(int value);
    bool verify_caster_level_is_correct(int value);
private:
    bool verify_bonus_is_within_boundaries(int min, int max, int value);
};
#endif