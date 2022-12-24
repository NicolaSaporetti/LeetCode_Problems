#ifndef ObjectRecipe_HPP
#define ObjectRecipe_HPP
#include <vector>
using namespace std;

typedef struct ObjectRecipe {
    int total_cost;
    int caster_level;
    vector<int> enchantment_levels;
} ObjectRecipe;
#endif