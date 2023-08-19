#include <vector>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,INT_MAX);
        dp[0]=0;
        for(int i=0;i<n;i++)
        {
            for(int j=1;j*j+i<=n;j++)
            {
                int v = j*j+i;
                dp[v] = min(dp[v],dp[i]+1);
            }
        }
        return dp[n];
    }
};