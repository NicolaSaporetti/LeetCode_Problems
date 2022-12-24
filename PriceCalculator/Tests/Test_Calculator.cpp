#include <iostream>
#include "TestBase.hpp"
#include "../ProductionCode/Calculator.cpp"
using namespace std;

class Test_Calculator : public Test_Base {
public:
    Test_Calculator() {}

    void run() override {
        cout<<"\nTest Calculator run"<<endl;
        test_calculate_cost_item_with_charges_rechargeable();
        test_calculate_cost_item_with_charges_non_rechargeable();
        test_calculate_cost_item_with_charges_hourly_rechargeable();
        test_calculate_cost_item_with_charges_daily_rechargeable();
        test_calculate_cost_item_with_charges_weekly_rechargeable();
        test_calculate_cost_item_with_charges_montly_rechargeable();
        test_calculate_cost_item_with_max_level_different_from_sum_levels();
        test_calculate_cost_permanent_item();
    }

private:
    void test_calculate_cost_item_with_charges_rechargeable()
    {
        cout<<"test_calculate_cost_item_with_charges_rechargeable run"<<endl;
        ItemWithCharges item_with_charges = {RechargeType::Recheargeable,{3},10};
        Calculator calculator;
        ItemSummary expected_result = {3000,6000,300,{3}};
        
        ItemSummary result = calculator.calculate_cost_item_with_charges(item_with_charges);
        verify_equal(result,expected_result);
    }
    void test_calculate_cost_item_with_charges_non_rechargeable()
    {
        cout<<"test_calculate_cost_item_with_charges_non_rechargeable run"<<endl;
        ItemWithCharges item_with_charges = {RechargeType::Non_recheargeable,{3},10};
        Calculator calculator;
        ItemSummary expected_result = {2400,4800,0,{3}};
        
        ItemSummary result = calculator.calculate_cost_item_with_charges(item_with_charges);
        verify_equal(result,expected_result);
    }
    void test_calculate_cost_item_with_charges_hourly_rechargeable()
    {
        cout<<"test_calculate_cost_item_with_charges_hourly_rechargeable run"<<endl;
        ItemWithCharges item_with_charges = {RechargeType::Hourly,{3},10};
        Calculator calculator;
        ItemSummary expected_result = {2400,12000,0,{3}};
        
        ItemSummary result = calculator.calculate_cost_item_with_charges(item_with_charges);
        verify_equal(result,expected_result);
    }
    void test_calculate_cost_item_with_charges_daily_rechargeable()
    {
        cout<<"test_calculate_cost_item_with_charges_daily_rechargeable run"<<endl;
        ItemWithCharges item_with_charges = {RechargeType::Daily,{3},10};
        Calculator calculator;
        ItemSummary expected_result = {2250,11250,0,{3}};
        
        ItemSummary result = calculator.calculate_cost_item_with_charges(item_with_charges);
        verify_equal(result,expected_result);
    }
    void test_calculate_cost_item_with_charges_weekly_rechargeable()
    {
        cout<<"test_calculate_cost_item_with_charges_weekly_rechargeable run"<<endl;
        ItemWithCharges item_with_charges = {RechargeType::Weekly,{3},10};
        Calculator calculator;
        ItemSummary expected_result = {2100,10500,0,{3}};
        
        ItemSummary result = calculator.calculate_cost_item_with_charges(item_with_charges);
        verify_equal(result,expected_result);
    }
    void test_calculate_cost_item_with_charges_montly_rechargeable()
    {
        cout<<"test_calculate_cost_item_with_charges_montly_rechargeable run"<<endl;
        ItemWithCharges item_with_charges = {RechargeType::Montly,{3},10};
        Calculator calculator;
        ItemSummary expected_result = {1950,9750,0,{3}};
        
        ItemSummary result = calculator.calculate_cost_item_with_charges(item_with_charges);
        verify_equal(result,expected_result);
    }
    void test_calculate_cost_item_with_max_level_different_from_sum_levels()
    {
        cout<<"test_calculate_cost_item_with_max_level_different_from_sum_levels run"<<endl;
        ItemWithCharges item_with_charges = {RechargeType::Recheargeable,{4,6,4,6},10};
        Calculator calculator;
        ItemSummary expected_result = {20000,40000,2000,{4,6,4,6}};
        
        ItemSummary result = calculator.calculate_cost_item_with_charges(item_with_charges);
        verify_equal(result,expected_result);
    }
    void test_calculate_cost_permanent_item()
    {
        cout<<"test_calculate_cost_permanent_item run"<<endl;
        PermanentItem item = {3};
        Calculator calculator;
        ItemSummary expected_result = {3000,18000,0,{3}};
        
        ItemSummary result = calculator.calculate_cost_permanent_item(item);
        verify_equal(result,expected_result);
    }
};
