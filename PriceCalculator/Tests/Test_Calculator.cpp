#include <assert.h>
#include <iostream>
#include "../ProductionCode/Calculator.cpp"
using namespace std;

class Test_Calculator {
public:
    Test_Calculator() {}

    void run() {
        cout<<"Test Calculator run"<<endl;
        test_calculate_cost_weapon();
        test_calculate_cost_weapon_with_inchantemt_price_below_100();
        test_calculate_cost_weapon_with_secondary_bonus();
        test_calculate_cost_armor();
        test_calculate_cost_armor_approximated();
        test_calculate_cost_armor_with_inchantemt_price_below_3000();
        test_calculate_cost_potion_with_one_doses();
        test_calculate_cost_potion_with_multiple_doses();
        test_calculate_cost_wand_rechargeable();
        test_calculate_cost_wand_non_rechargeable();
    }

private:
    void test_calculate_cost_weapon()
    {
        Weapon weapon = {10,10,1};
        Calculator calculator;

        ItemSummary wcs = calculator.calculate_cost_weapon(weapon);
        assert(500==wcs.price);
    }
    void test_calculate_cost_weapon_with_inchantemt_price_below_100()
    {
        Weapon weapon = {10,1,2};
        Calculator calculator;

        ItemSummary wcs = calculator.calculate_cost_weapon(weapon);
        assert(200==wcs.price);
    }
    void test_calculate_cost_weapon_with_secondary_bonus()
    {
        Weapon weapon = {10,10,2,3};
        Calculator calculator;

        ItemSummary wcs = calculator.calculate_cost_weapon(weapon);
        assert(1750==wcs.price);
    }
    void test_calculate_cost_armor()
    {
        Armor weapon = {30,600,1};
        Calculator calculator;

        ItemSummary wcs = calculator.calculate_cost_armor(weapon);
        assert(6000==wcs.price);
    }
    void test_calculate_cost_armor_approximated()
    {
        Armor weapon = {40,400,1};
        Calculator calculator;

        ItemSummary wcs = calculator.calculate_cost_armor(weapon);
        assert(5340==wcs.price);
    }
    void test_calculate_cost_armor_with_inchantemt_price_below_3000()
    {
        Armor weapon = {10,300,1};
        Calculator calculator;

        ItemSummary wcs = calculator.calculate_cost_armor(weapon);
        assert(3000==wcs.price);
    }
    void test_calculate_cost_potion_with_one_doses()
    {
        Potion potion = {3,1};
        Calculator calculator;

        ItemSummary wcs = calculator.calculate_cost_potion(potion);
        assert(2640==wcs.price);
    }
    void test_calculate_cost_potion_with_multiple_doses()
    {
        Potion potion = {5,3};
        Calculator calculator;
        
        ItemSummary wcs = calculator.calculate_cost_potion(potion);
        assert(5200==wcs.price);
    }
    void test_calculate_cost_scroll()
    {
        Scroll scroll = {15};
        Calculator calculator;
        
        ItemSummary wcs = calculator.calculate_cost_scroll(scroll);
        assert(12000==wcs.price);
    }
    void test_calculate_cost_wand_rechargeable()
    {
        Wand wand = {3,10,true};
        Calculator calculator;
        
        ItemSummary wcs = calculator.calculate_cost_wand(wand);
        assert(6000==wcs.price);
    }
    void test_calculate_cost_wand_non_rechargeable()
    {
        Wand wand = {3,10,false};
        Calculator calculator;
        
        ItemSummary wcs = calculator.calculate_cost_wand(wand);
        assert(4800==wcs.price);
    }
};
