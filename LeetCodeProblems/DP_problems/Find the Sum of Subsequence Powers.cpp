#include <vector>
using namespace std;

class Solution {
public:
    int mod = 1e9 + 7;
    int dp[51][51][51][51]; //index, numberLeft, Startmin, Endmin
    int n;
    int solve(int idx, int k, int x, int y, vector<int>& nums){
        if(k == 0){
            int mini = nums[y] - nums[x];
            return mini;
        }
        if(idx >= n) return 0;
        if(dp[idx][k][x][y] != -1) return dp[idx][k][x][y];
        long long sum = 0;
        for(int j=idx; j<n; j++){
            int prev = idx - 1;
            if(prev == -1) sum = (sum + solve(j+1, k-1, x, y, nums)) % mod;
            else{
                int val = nums[j] - nums[prev];
                int mini = nums[y] - nums[x];
                if(val < mini) sum = (sum + solve(j+1, k-1, prev, j, nums)) % mod;
                else sum = (sum + solve(j+1, k-1, x, y, nums)) % mod;
            }
        }
        return dp[idx][k][x][y] = sum;
    }
    int sumOfPowers(vector<int>& nums, int k) {
        memset(dp, -1, sizeof dp);
        n = nums.size();
        sort(nums.begin(), nums.end());
        return solve(0, k, 0, n-1, nums);
    }
};