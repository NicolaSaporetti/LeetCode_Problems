#include <vector>
using namespace std;

class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        int mod = 1e9+7;
        vector<vector<vector<int>>> dp(zero+1,vector<vector<int>>(one+1,vector<int>(2)));
        for(int i=1;i<min(zero+1,limit+1);i++) dp[i][0][0] = 1;
        for(int i=1;i<min(one+1,limit+1);i++) dp[0][i][1] = 1;

        for (int i = 1; i <= zero; i++) {
            for (int j = 1; j <= one; j++) {
                dp[i][j][0] = (dp[i-1][j][0] + dp[i-1][j][1]) % mod;
                if (i-1-limit >= 0) dp[i][j][0] = (dp[i][j][0] + mod - dp[i-1-limit][j][1]) % mod;
                dp[i][j][1] = (dp[i][j-1][0] + dp[i][j-1][1]) % mod;
                if (j-1-limit >= 0) dp[i][j][1] = (dp[i][j][1] + mod - dp[i][j-1-limit][0]) % mod;
            }
        }
        return (dp[zero][one][0] + dp[zero][one][1]) % mod;
    }
};