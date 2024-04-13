#include <vector>
using namespace std;

class Solution {
public:
    int specialPerm(vector<int>& nums) {
        sz = nums.size();
        dp.assign(sz,vector<int>(1<<sz,-1));
        int r = 0;
        for(int i=0;i<sz;i++) r = (r+dfs(i,(1<<i),nums))%mod;
        return r;
    }
private:
    int dfs(int prev,int num, vector<int>& nums)
    {
        int pos = 0;
        for(int i=0;i<sz;i++) if((1<<i)&num) pos++;
        if(pos>=sz) return 1;
        else if(dp[prev][num]!=-1) return dp[prev][num];
        else
        {
            int v = 0;
            for(int i=0;i<sz;i++)
            {
                if(!((1<<i)&num) && (nums[i]%nums[prev]==0 || nums[prev]%nums[i]==0))
                {
                    v=(v+dfs(i,num|(1<<i),nums))%mod;
                }
            }
            return dp[prev][num]=v;
        }
    }

    vector<vector<int>> dp;
    int mod = 1e9+7;
    int sz;
};