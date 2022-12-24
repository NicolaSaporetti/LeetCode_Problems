#ifndef ObjectCreationSummary_HPP
#define ObjectCreationSummary_HPP
#include <vector>
using namespace std;

typedef struct ObjectCreationSummary {
    int days_to_create;
    int material_cost;
    int labor_cost;
    int total_cost;
    vector<int> rolls_required;
} ObjectCreationSummary;
#endif