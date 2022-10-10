#include <vector>
using namespace std;

class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(target + 1, vector<int>(n + 1, 0));
        int MOD = 1000000007;
        dp[0][0] = 1;
        for(int sum = 1; sum <= target; ++sum)
        {
            for(int num = 1; num <= n; ++num)
            {
                for(int face = 1; face <= k && sum - face >= 0; ++face)
                {
                    dp[sum][num] = (dp[sum][num] + dp[sum-face][num-1]) % MOD;
                }
            }
        }
        return dp[target][n];
    }
};