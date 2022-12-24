#include "ObjectCreator.hpp"
#include "ObjectCreationSummary.hpp"
#include "ObjectRecipe.hpp"
using namespace std;

ObjectCreationSummary ObjectCreator::calculate_cost_magic_object(const ObjectRecipe& object_recipe)
{
    ObjectCreationSummary object_summary = {};
    object_summary.rolls_required = compute_roll_required(object_recipe.enchantment_levels,object_recipe.caster_level);
    object_summary.days_to_create = compute_days_to_create(object_recipe.total_cost, object_summary.rolls_required);
    object_summary.material_cost = adjust_price_based_on_difficulty(object_recipe.total_cost, object_summary.rolls_required);
    object_summary.labor_cost = compute_labor_cost(object_recipe.caster_level, object_summary.days_to_create);
    object_summary.total_cost = object_summary.material_cost+object_summary.labor_cost;
    return object_summary;
}

int ObjectCreator::compute_days_to_create(int base_cost, const vector<int>& rolls)
{
    const int base_days = 7;
    int days_to_create = base_cost/1000+((base_cost%1000!=0)? 1 : 0);
    return adjust_price_based_on_difficulty(base_days + days_to_create, rolls);
}

vector<int> ObjectCreator::compute_roll_required(const vector<int>& enchantment_levels, int caster_level)
{
    vector<int> rolls;
    for(size_t idx=0; idx<enchantment_levels.size(); idx++)
    {
        rolls.push_back(min(compute_percentage(caster_level,enchantment_levels[idx]),100));
    }
    return rolls;
}

int ObjectCreator::compute_percentage(int caster_level, int enchantment_levels)
{
    const int intelligence = 18;
    const int bonus_meditation = caster_level/5+((caster_level%5!=0)? 1 : 0);
    return (intelligence+bonus_meditation+caster_level)*2-enchantment_levels*3;
}

int ObjectCreator::compute_labor_cost(int caster_level, int days_to_create)
{
    const int day_in_a_month = 28;
    const int cost_by_level = 500;
    int daily_cost = (500*caster_level)/day_in_a_month;
    return days_to_create*daily_cost;
}

int ObjectCreator::adjust_price_based_on_difficulty(int base_cost, const vector<int>& rolls)
{
    for(const auto& roll : rolls)
    {
        base_cost*=100;
        base_cost/=roll;
    }
    return base_cost;
}