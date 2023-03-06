#include <vector>
using namespace std;

class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int sz = nums.size();
        sort(begin(nums),end(nums));
        int diff = INT_MAX;
        diff = min(nums[sz-1]-nums[2],diff);
        diff = min(nums[sz-2]-nums[1],diff);
        diff = min(nums[sz-3]-nums[0],diff);
        return diff;
    }
};