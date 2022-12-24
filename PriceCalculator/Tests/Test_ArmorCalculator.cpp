#include <iostream>
#include "TestBase.hpp"
#include "../ProductionCode/ArmorCalculator.cpp"
using namespace std;

class Test_ArmorCalculator : public Test_Base
{
public:
    Test_ArmorCalculator() {}

    void run() override {
        cout<<"\nTest ArmorCalculator run"<<endl;
        test_calculate_cost_armor();
        test_calculate_cost_armor_approximated();
        test_calculate_cost_armor_with_inchantemt_price_below_3000();
    }

private:
    void test_calculate_cost_armor()
    {
        cout<<"test_calculate_cost_armor run"<<endl;
        Armor weapon = {ArmorType::Piastre,1};
        Calculator calculator;
        ItemSummary expected_result = {10000,10000,0,{1}};

        ItemSummary result = calculator.calculate_cost_armor(weapon);
        verify_equal(result,expected_result);
    }
    void test_calculate_cost_armor_approximated()
    {
        cout<<"test_calculate_cost_armor_approximated run"<<endl;
        Armor weapon = {ArmorType::Maglia,1};
        Calculator calculator;
        ItemSummary expected_result = {5340,5340,0,{1}};

        ItemSummary result = calculator.calculate_cost_armor(weapon);
        verify_equal(result,expected_result);
    }
    void test_calculate_cost_armor_with_inchantemt_price_below_3000()
    {
        cout<<"test_calculate_cost_armor_with_inchantemt_price_below_3000 run"<<endl;
        Armor weapon = {ArmorType::Scudo,1};
        Calculator calculator;
        ItemSummary expected_result = {3000,3000,0,{1}};

        ItemSummary result = calculator.calculate_cost_armor(weapon);
        verify_equal(result,expected_result);
    }
};
