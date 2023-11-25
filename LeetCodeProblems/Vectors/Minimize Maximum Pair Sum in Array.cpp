#include <vector>
using namespace std;

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int sz = nums.size();
        sort(begin(nums),end(nums));
        int maxE = 0;
        for(int i=0;i<sz/2;i++) maxE = max(maxE, nums[i]+nums[sz-1-i]);
        return maxE;
    }
};