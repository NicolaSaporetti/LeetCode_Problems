#include <vector>
using namespace std;

class Solution {
    public:
    int numberOfSets(int n, int k) {
        int mod = 1e9+7;
        vector<vector<long long>> dp(n+1,vector<long long>(n+1,0));
        
        for (int i = 2; i <= n; i++) {
            dp[i][i-1] = 1;
            dp[i][1] = i * (i - 1) / 2;
        }
        for (int i = 4; i <= n; i++) {
            for (int j = 2; j < i; j++) {
                dp[i][j] = (2*dp[i-1][j] - dp[i-2][j]+ dp[i-1][j-1] + mod)%mod;
            }
        }
        
        return dp[n][k];
    }
};