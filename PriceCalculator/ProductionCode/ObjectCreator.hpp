#ifndef ObjectCreator_HPP
#define ObjectCreator_HPP

#include "ObjectCreationSummary.hpp"
#include "ObjectRecipe.hpp"
using namespace std;

class ObjectCreator {
public:
    ObjectCreationSummary calculate_cost_magic_object(const ObjectRecipe& object_recipe);
private:
    int compute_days_to_create(int base_cost, const vector<int>& rolls);
    vector<int> compute_roll_required(const vector<int>& enchantment_levels, int caster_level);
    int compute_percentage(int caster_level, int enchantment_levels);
    int compute_labor_cost(int caster_level, int days_to_create);
    int adjust_price_based_on_difficulty(int base_cost, const vector<int>& rolls);
};
#endif