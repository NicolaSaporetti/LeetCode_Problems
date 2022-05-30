#include <iostream>
#include <vector>

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;
        for (int i=0;i<nums.size();i++) {
            int height = nums[i];
            int left = lower_bound(dp.begin(), dp.end(), height) - dp.begin();
            if (left == dp.size()) dp.push_back(height);
            dp[left] = height;
        }
        for (int i=0;i<dp.size();i++) {
            cout<<dp[i]<<endl;
        }
        return dp.size();
    }
};

int main()
{
    Solution solution;
    return 0;
}