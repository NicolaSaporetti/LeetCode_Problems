#include <vector>
using namespace std;

class Solution {
public:
    int countOrders(int n) {
        vector<long long> dp(n+1,-1);
        int mod = 1e9+7;
        dp[0]=1;
        for(long long i=1;i<=n;i++) dp[i] = ((dp[i-1]*(2*i-1))%mod * i)%mod;
        return dp[n];
    }
};