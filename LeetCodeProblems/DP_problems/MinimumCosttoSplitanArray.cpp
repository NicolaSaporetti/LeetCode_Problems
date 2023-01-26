#include <vector>
using namespace std;

class Solution {
public:
    int minCost(vector<int>& nums, int k) {
        pay = k;
        sz = nums.size();
        dp.assign(sz,-1);
        return solve(0,nums);
    }
private:
    int solve(int s, vector<int>&nums){
        if(s >= sz) return 0;
        if(dp[s] != -1) return dp[s];

        vector<int> mp(sz,0);
        int cnt = 0;
        int ans = INT_MAX;
        for(int j = s;j < sz;j++){
            mp[nums[j]]++;
            if(mp[nums[j]] == 2) cnt += 2;
            else if(mp[nums[j]] > 2) cnt++;
            ans = min(ans,solve(j+1,nums)+cnt+pay);
        }
        return dp[s] = ans;
    }

    vector<int> dp;
    int sz;
    int pay;
};