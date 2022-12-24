#include <iostream>
#include <assert.h>
#include "TestBase.hpp"
#include "../ProductionCode/InputValidation.cpp"
using namespace std;

class Test_InputValidation : public Test_Base
{
public:
    Test_InputValidation() {}

    void run() override {
        cout<<"\nTest InputValidation run"<<endl;
        test_verify_bonus_is_equal_to_min();
        test_verify_bonus_is_equal_to_max();
        test_verify_bonus_is_valid();
        test_verify_bonus_is_above_max();
        test_verify_bonus_is_below_min();

        test_verify_secondary_bonus_is_equal_to_min();
        test_verify_secondary_bonus_is_equal_to_max();
        test_verify_secondary_bonus_is_valid();
        test_verify_secondary_bonus_is_above_max();
        test_verify_secondary_bonus_is_below_min();

        test_verify_level_is_equal_to_min();
        test_verify_level_is_equal_to_max();
        test_verify_level_is_valid();
        test_verify_level_is_above_max();
        test_verify_level_is_below_min();

        test_verify_doses_is_equal_to_min();
        test_verify_doses_is_equal_to_max();
        test_verify_doses_is_valid();
        test_verify_doses_is_above_max();
        test_verify_doses_is_below_min();

        test_verify_number_of_spells_is_equal_to_min();
        test_verify_number_of_spells_is_valid();
        test_verify_number_of_spells_is_below_min();

        test_verify_charges_is_equal_to_min();
        test_verify_charges_is_equal_to_max();
        test_verify_charges_is_valid();
        test_verify_charges_is_above_max();
        test_verify_charges_is_below_min();

        test_verify_caster_level_is_equal_to_min();
        test_verify_caster_level_is_equal_to_max();
        test_verify_caster_level_is_valid();
        test_verify_caster_level_is_above_max();
        test_verify_caster_level_is_below_min();
    }

private:
    void test_verify_bonus_is_equal_to_min()
    {
        cout<<"test_verify_bonus_is_equal_to_min run"<<endl;
        InputValidation input_validation;
        assert(input_validation.verify_bonus_is_correct(1));
    }
    void test_verify_bonus_is_equal_to_max()
    {
        cout<<"test_verify_bonus_is_equal_to_max run"<<endl;
        InputValidation input_validation;
        assert(input_validation.verify_bonus_is_correct(5));
    }
    void test_verify_bonus_is_valid()
    {
        cout<<"test_verify_bonus_is_valid run"<<endl;
        InputValidation input_validation;
        assert(input_validation.verify_bonus_is_correct(3));
    }
    void test_verify_bonus_is_above_max()
    {
        cout<<"test_verify_bonus_is_above_max run"<<endl;
        InputValidation input_validation;
        assert(!input_validation.verify_bonus_is_correct(6));
    }
    void test_verify_bonus_is_below_min()
    {
        cout<<"test_verify_bonus_is_below_min run"<<endl;
        InputValidation input_validation;
        assert(!input_validation.verify_bonus_is_correct(-20));
    }

    void test_verify_secondary_bonus_is_equal_to_min()
    {
        cout<<"test_verify_secondary_bonus_is_equal_to_min run"<<endl;
        InputValidation input_validation;
        assert(input_validation.verify_secondary_bonus_is_correct(1));
    }
    void test_verify_secondary_bonus_is_equal_to_max()
    {
        cout<<"test_verify_secondary_bonus_is_equal_to_max run"<<endl;
        InputValidation input_validation;
        assert(input_validation.verify_secondary_bonus_is_correct(5));
    }
    void test_verify_secondary_bonus_is_valid()
    {
        cout<<"test_verify_secondary_bonus_is_valid run"<<endl;
        InputValidation input_validation;
        assert(input_validation.verify_secondary_bonus_is_correct(3));
    }
    void test_verify_secondary_bonus_is_above_max()
    {
        cout<<"test_verify_secondary_bonus_is_above_max run"<<endl;
        InputValidation input_validation;
        assert(!input_validation.verify_secondary_bonus_is_correct(6));
    }
    void test_verify_secondary_bonus_is_below_min()
    {
        cout<<"test_verify_secondary_bonus_is_below_min run"<<endl;
        InputValidation input_validation;
        assert(!input_validation.verify_secondary_bonus_is_correct(-20));
    }

    void test_verify_level_is_equal_to_min()
    {
        cout<<"test_verify_level_is_equal_to_min run"<<endl;
        InputValidation input_validation;
        assert(input_validation.verify_spell_level_is_correct(1));
    }
    void test_verify_level_is_equal_to_max()
    {
        cout<<"test_verify_level_is_equal_to_max run"<<endl;
        InputValidation input_validation;
        assert(input_validation.verify_spell_level_is_correct(9));
    }
    void test_verify_level_is_valid()
    {
        cout<<"test_verify_level_is_valid run"<<endl;
        InputValidation input_validation;
        assert(input_validation.verify_spell_level_is_correct(3));
    }
    void test_verify_level_is_above_max()
    {
        cout<<"test_verify_level_is_above_max run"<<endl;
        InputValidation input_validation;
        assert(!input_validation.verify_spell_level_is_correct(29));
    }
    void test_verify_level_is_below_min()
    {
        cout<<"test_verify_level_is_below_min run"<<endl;
        InputValidation input_validation;
        assert(!input_validation.verify_spell_level_is_correct(-10));
    }

    void test_verify_doses_is_equal_to_min()
    {
        cout<<"test_verify_doses_is_equal_to_min run"<<endl;
        InputValidation input_validation;
        assert(input_validation.verify_doses_are_correct(1));
    }
    void test_verify_doses_is_equal_to_max()
    {
        cout<<"test_verify_doses_is_equal_to_max run"<<endl;
        InputValidation input_validation;
        assert(input_validation.verify_doses_are_correct(3));
    }
    void test_verify_doses_is_valid()
    {
        cout<<"test_verify_doses_is_valid run"<<endl;
        InputValidation input_validation;
        assert(input_validation.verify_doses_are_correct(2));
    }
    void test_verify_doses_is_above_max()
    {
        cout<<"test_verify_doses_is_above_max run"<<endl;
        InputValidation input_validation;
        assert(!input_validation.verify_doses_are_correct(29));
    }
    void test_verify_doses_is_below_min()
    {
        cout<<"test_verify_doses_is_below_min run"<<endl;
        InputValidation input_validation;
        assert(!input_validation.verify_doses_are_correct(-10));
    }

    void test_verify_number_of_spells_is_equal_to_min()
    {
        cout<<"test_verify_number_of_spells_is_equal_to_min run"<<endl;
        InputValidation input_validation;
        assert(input_validation.verify_number_of_spells(1));
    }
    void test_verify_number_of_spells_is_valid()
    {
        cout<<"test_verify_number_of_spells_is_valid run"<<endl;
        InputValidation input_validation;
        assert(input_validation.verify_number_of_spells(70));
    }
    void test_verify_number_of_spells_is_below_min()
    {
        cout<<"test_verify_number_of_spells_is_below_min run"<<endl;
        InputValidation input_validation;
        assert(!input_validation.verify_number_of_spells(0));
    }

    void test_verify_charges_is_equal_to_min()
    {
        cout<<"test_verify_charges_is_equal_to_min run"<<endl;
        InputValidation input_validation;
        assert(input_validation.verify_charges_are_correct(1));
    }
    void test_verify_charges_is_equal_to_max()
    {
        cout<<"test_verify_charges_is_equal_to_max run"<<endl;
        InputValidation input_validation;
        assert(input_validation.verify_charges_are_correct(3));
    }
    void test_verify_charges_is_valid()
    {
        cout<<"test_verify_charges_is_valid run"<<endl;
        InputValidation input_validation;
        assert(input_validation.verify_charges_are_correct(40));
    }
    void test_verify_charges_is_above_max()
    {
        cout<<"test_verify_charges_is_above_max run"<<endl;
        InputValidation input_validation;
        assert(!input_validation.verify_charges_are_correct(49));
    }
    void test_verify_charges_is_below_min()
    {
        cout<<"test_verify_charges_is_below_min run"<<endl;
        InputValidation input_validation;
        assert(!input_validation.verify_charges_are_correct(0));
    }

    void test_verify_caster_level_is_equal_to_min()
    {
        cout<<"test_verify_caster_level_is_equal_to_min run"<<endl;
        InputValidation input_validation;
        assert(input_validation.verify_caster_level_is_correct(9));
    }
    void test_verify_caster_level_is_equal_to_max()
    {
        cout<<"test_verify_caster_level_is_equal_to_max run"<<endl;
        InputValidation input_validation;
        assert(input_validation.verify_caster_level_is_correct(36));
    }
    void test_verify_caster_level_is_valid()
    {
        cout<<"test_verify_caster_level_is_valid run"<<endl;
        InputValidation input_validation;
        assert(input_validation.verify_caster_level_is_correct(20));
    }
    void test_verify_caster_level_is_above_max()
    {
        cout<<"test_verify_caster_level_is_above_max run"<<endl;
        InputValidation input_validation;
        assert(!input_validation.verify_caster_level_is_correct(40));
    }
    void test_verify_caster_level_is_below_min()
    {
        cout<<"test_verify_caster_level_is_below_min run"<<endl;
        InputValidation input_validation;
        assert(!input_validation.verify_caster_level_is_correct(8));
    }
};
