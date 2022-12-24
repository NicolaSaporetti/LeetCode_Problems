#ifndef ItemSummary_HPP
#define ItemSummary_HPP
#include <vector>
using namespace std;

typedef struct ItemSummary {
    int initial_enchantment_cost;
    int total_cost;
    int charge_cost;
    vector<int> enchantment_levels;
} ItemSummary;
#endif