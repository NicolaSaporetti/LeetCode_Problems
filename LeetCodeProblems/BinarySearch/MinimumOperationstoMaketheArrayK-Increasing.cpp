#include <vector>
using namespace std;

class Solution {
public:
    int kIncreasing(vector<int>& arr, int k) {
        int tot = 0;
        vector<vector<int>> series(k);
        int sz = arr.size();
        for(int i=0;i<sz;i++)
        {
            series[i%k].push_back(arr[i]);
        }
        for(int i=0;i<k;i++)
        {
            tot+=series[i].size()-lengthOfLIS(series[i]);
        }
        return tot;
    }
    
private:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;
        for (int i=0;i<nums.size();i++) {
            int left = upper_bound(dp.begin(), dp.end(), nums[i]) - dp.begin();
            if (left == dp.size()) dp.push_back(nums[i]);
            dp[left] = nums[i];
        }
        return dp.size();
    }
};