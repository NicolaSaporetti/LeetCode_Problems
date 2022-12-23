#ifndef CommandLine_HPP
#define CommandLine_HPP

#include "WeaponCostSummary.hpp"
#include "Calculator.hpp"
using namespace std;

class CommandLine {
public:
    CommandLine() {}
    WeaponCostSummary compute_cost();
private:
    int fill_cost();
    int fill_encoumber();
    int fill_primary_bonus();
    int fill_secondary_bonus();

    Calculator calculator;
};
#endif