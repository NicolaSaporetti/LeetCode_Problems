#include <vector>
using namespace std;

class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        long long v = 0;
        for(auto& e : nums) v+=(long long)e;
        long long dif = abs(goal-v);
        return dif/(long long)limit+((dif%(long long)limit==0)? 0 : 1);
    }
};