#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int sz = nums.size();
        vector<int> dp(target+1,-1);
        dp[0]=0;
        for(int i=0;i<sz;i++)
        {
            for(int j=target-1;j>=0;j--)
            {
                int e = j+nums[i];
                if(dp[j]!=-1 && e<=target) dp[e]=max(dp[e],1+dp[j]);
            }
        }
        return dp[target];
    }
};
