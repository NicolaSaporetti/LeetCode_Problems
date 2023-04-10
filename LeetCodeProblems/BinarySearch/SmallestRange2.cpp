#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        int sz = nums.size();
        sort(nums.begin(),nums.end());
        int ans = nums[sz-1] - nums[0];

        for (int i = 0; i < nums.size() - 1; ++i) {
            int high = max(nums[sz-1] - k, nums[i] + k);
            int low = min(nums[0] + k, nums[i+1] - k);
            ans = min(ans, high - low);
        }
        return ans;
    }
};