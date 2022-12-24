#include <iostream>
#include "TestBase.hpp"
#include "../ProductionCode/WeaponCalculator.cpp"
using namespace std;

class Test_WeaponCalculator : public Test_Base {
public:
    Test_WeaponCalculator() {}

    void run() override {
        cout<<"\nTest WeaponCalculator run"<<endl;
        test_calculate_cost_weapon();
        test_calculate_cost_weapon_with_inchantment_price_below_100();
        test_calculate_cost_weapon_with_secondary_bonus();
        test_calculate_cost_weapon_with_third_bonus();
    }

private:
    void test_calculate_cost_weapon()
    {
        cout<<"test_calculate_cost_weapon run"<<endl;
        Weapon weapon = {WeaponType::Mazza,1,0};
        WeaponCalculator creator;
        ItemSummary expected_result = {750,750,0,{1}};

        ItemSummary result = creator.calculate_cost_weapon(weapon);
        verify_equal(result,expected_result);
    }
    void test_calculate_cost_weapon_with_inchantment_price_below_100()
    {
        cout<<"test_calculate_cost_weapon_with_inchantment_price_below_100 run"<<endl;
        Weapon weapon = {WeaponType::Cerbottana_piccola,2,0};
        WeaponCalculator creator;
        ItemSummary expected_result = {100,200,0,{2}};

        ItemSummary result = creator.calculate_cost_weapon(weapon);
        verify_equal(result,expected_result);
    }
    void test_calculate_cost_weapon_with_secondary_bonus()
    {
        cout<<"test_calculate_cost_weapon_with_secondary_bonus run"<<endl;
        Weapon weapon = {WeaponType::Mazza,2,3};
        WeaponCalculator creator;
        ItemSummary expected_result = {750,2625,0,{2,3}};

        ItemSummary result = creator.calculate_cost_weapon(weapon);
        verify_equal(result,expected_result);
    }
    void test_calculate_cost_weapon_with_third_bonus()
    {
        cout<<"test_calculate_cost_weapon_with_third_bonus run"<<endl;
        Sword sword = {WeaponType::Spada,2,3,4};
        WeaponCalculator creator;
        ItemSummary expected_result = {3000,16500,0,{2,3,4}};

        ItemSummary result = creator.calculate_cost_sword(sword);
        verify_equal(result,expected_result);
    }
};
