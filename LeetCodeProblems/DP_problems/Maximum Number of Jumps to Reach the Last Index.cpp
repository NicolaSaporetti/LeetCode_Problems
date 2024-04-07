#include <vector>
using namespace std;

class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int sz = nums.size();
        vector<int> dp(sz,-1);
        dp[0]=0;
        for(int i=1;i<sz;i++)
            for(int j=0;j<i;j++)
                if(dp[j]!=-1 && abs(nums[i]-nums[j])<=target)
                {
                    dp[i]=max(dp[i],dp[j]+1);
                }
        return dp[sz-1];
    }
};