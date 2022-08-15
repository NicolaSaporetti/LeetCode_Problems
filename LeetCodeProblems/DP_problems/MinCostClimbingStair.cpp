#include <iostream>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int sz = cost.size();
        for(int i=2;i<sz;i++)
        {
            cost[i]+=min(cost[i-1],cost[i-2]);
        }
        return min(cost[sz-1], cost[sz-2]);
    }
};