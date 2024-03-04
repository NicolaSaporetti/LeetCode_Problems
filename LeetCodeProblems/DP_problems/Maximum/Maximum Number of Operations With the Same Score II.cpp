#include <vector>
using namespace std;

class Solution {
public:
    int maxOperations(vector<int>& nums) {
        sz = nums.size();
        dp.assign(sz,vector<int>(sz,-1));
        int tot1 = compute(nums,nums[0]+nums[1],0,sz-1);
        dp.assign(sz,vector<int>(sz,-1));
        int tot2 = compute(nums,nums[sz-1]+nums[sz-2],0,sz-1);
        dp.assign(sz,vector<int>(sz,-1));
        int tot3 = compute(nums,nums[0]+nums[sz-1],0,sz-1);
        return max(tot1,max(tot2,tot3));
    }
private:
    int compute(vector<int>& nums, int v1, int p1, int p2)
    {
        if(p1>=p2) return 0;
        else if(dp[p1][p2]!=-1) return dp[p1][p2];
        else
        {
            int v = 0;
            if(nums[p1]+nums[p1+1]==v1)
            {
                v = 1+compute(nums,v1,p1+2,p2);
            }
            if(nums[p2]+nums[p2-1]==v1)
            {
                v = max(v, 1+compute(nums,v1,p1,p2-2));
            }
            if(nums[p1]+nums[p2]==v1)
            {
                v = max(v, 1+compute(nums,v1,p1+1,p2-1));
            }
            return dp[p1][p2]=v;
        }
    }
    int sz;
    vector<vector<int>> dp;
};