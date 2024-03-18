#include <vector>
#include "binpow.cpp"
using namespace std;

class Solution {
public:
    int sumOfPower(vector<int>& nums, int k) {
        sz = nums.size();
        dp.assign(sz,vector<vector<int>>(sz,vector<int>(k+1,-1)));
        return dfs(0,0,k,nums);
    }
private:
    long long dfs(int idx, int size, int k, vector<int>& nums)
    {
        if(k==0) return binpowWithModulo(2,sz-size,mod);
        else if(idx>=sz || k<0) return 0;
        else if(dp[idx][size][k]!=-1) return dp[idx][size][k];
        {
            return dp[idx][size][k]=(dfs(idx+1,size,k,nums)+dfs(idx+1,size+1,k-nums[idx],nums))%mod;
        }
    }

    vector<vector<vector<int>>> dp;
    int sz;
    int mod = 1e9+7;
};