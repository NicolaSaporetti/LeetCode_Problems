#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()==1) return true;
        int n=nums.size();
        vector<bool> dp(n,false);
        dp[0]=true;
        for(int i=0;i<n;i++)
        {
            if(dp[i])
            {
                for(int j=min(i+nums[i],n-1);j>=i+1;j--)
                {
                    if(j==n-1) return true;
                    dp[j]=true;
                }
            }
        }
        return false;
    }
};