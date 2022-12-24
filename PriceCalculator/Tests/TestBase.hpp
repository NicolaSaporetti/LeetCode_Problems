#ifndef Test_Base_HPP
#define Test_Base_HPP
#include <iostream>
#include "../ProductionCode/ItemSummary.hpp"
#include "../ProductionCode/ObjectCreationSummary.hpp"
using namespace std;

class Test_Base {
public:
    Test_Base() = default;
    virtual ~Test_Base() = default;

    virtual void run() = 0;
    
protected:
    void verify_equal(const ItemSummary& result, const ItemSummary& expected_result)
    {
        if(result.initial_enchantment_cost!=expected_result.initial_enchantment_cost)
            cout<<"Wrong initial enchantment cost, result: "<<result.initial_enchantment_cost<<" expected: "<<expected_result.initial_enchantment_cost<<endl;
        if(result.total_cost!=expected_result.total_cost)
            cout<<"Wrong total cost, result: "<<result.total_cost<<" expected: "<<expected_result.total_cost<<endl;
        if(result.charge_cost!=expected_result.charge_cost)
            cout<<"Wrong charge cost, result: "<<result.charge_cost<<" expected: "<<expected_result.charge_cost<<endl;
        for(std::size_t i=0;i<result.enchantment_levels.size();i++)
            if(result.enchantment_levels[i]!=expected_result.enchantment_levels[i])
                cout<<"Wrong enchantment level,("<<i<<") result: "<<result.enchantment_levels[i]<<" expected: "<<expected_result.enchantment_levels[i]<<endl;
    }
    
    void verify_equal(const ObjectCreationSummary& result, const ObjectCreationSummary& expected_result)
    {
        if(result.days_to_create!=expected_result.days_to_create)
            cout<<"Wrong days to create, result: "<<result.days_to_create<<" expected: "<<expected_result.days_to_create<<endl;
        if(result.material_cost!=expected_result.material_cost)
            cout<<"Wrong material cost, result: "<<result.material_cost<<" expected: "<<expected_result.material_cost<<endl;
        if(result.labor_cost!=expected_result.labor_cost)
            cout<<"Wrong labor cost, result: "<<result.labor_cost<<" expected: "<<expected_result.labor_cost<<endl;
        if(result.total_cost!=expected_result.total_cost)
            cout<<"Wrong total cost, result: "<<result.total_cost<<" expected: "<<expected_result.total_cost<<endl;
        for(std::size_t i=0;i<result.rolls_required.size();i++)
            if(result.rolls_required[i]!=expected_result.rolls_required[i])
                cout<<"Wrong rolls required,("<<i<<") result: "<<result.rolls_required[i]<<" expected: "<<expected_result.rolls_required[i]<<endl;
    }
};
#endif
