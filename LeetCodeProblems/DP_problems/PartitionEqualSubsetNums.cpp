#include <vector>
using namespace std;

class Solution {
public:
    bool helper(int sum, vector<int>& nums, int ind, int rea, vector<vector<int>>&dp) {
        if(sum==rea) return true;
        if(ind<0) return false;
        if(dp[ind][sum]!=-1) return dp[ind][sum];
        bool nt = helper(sum, nums, ind-1, rea, dp);
        bool ta = helper(sum-nums[ind],nums, ind-1, rea+nums[ind], dp);
        
        return dp[ind][sum] = nt || ta;
    }
    
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        
        if(sum%2==1)return false;
        
        vector<vector<int>>dp(n, vector<int> (sum+1,-1));
        
        return helper(sum, nums, nums.size()-1, 0, dp);
    }
};