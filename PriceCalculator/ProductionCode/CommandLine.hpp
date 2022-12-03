#ifndef CommandLine_HPP
#define CommandLine_HPP

#include "ItemSummary.hpp"
#include "Calculator.hpp"
using namespace std;

class CommandLine {
public:
    CommandLine() {}
    ItemSummary compute_cost();
private:
    int fill_cost();
    int fill_encoumber();
    int fill_primary_bonus();
    int fill_secondary_bonus();
    int fill_spell_level();
    int fill_doses();
    int fill_spell_levels();
    int fill_int();
    bool is_rechargeable();

    Calculator calculator;
};
#endif