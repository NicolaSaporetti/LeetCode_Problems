#include <vector>
using namespace std;

class Solution {
public:
    int dfs(int i, int n, int x) {
        if(n==0) return 1;
        else if (pow(i, x) > n) return 0;
        else if(dp[i][n]!=-1) return dp[i][n];
        else return dp[i][n] = (dfs(i + 1, n - pow(i, x), x) + dfs(i + 1, n, x))%mod;
    }
    int numberOfWays(int n, int x) {
        dp.assign(n+1,vector<int>(n+1,-1));
        return dfs(1, n, x);
    }
private:
    vector<vector<int>> dp;
    int mod = 1e9+7;
};