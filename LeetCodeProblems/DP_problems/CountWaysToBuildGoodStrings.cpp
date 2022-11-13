#include <vector>
using namespace std;

class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<long long> dp(high+1,0);
        int mod = 1000000007;
        dp[zero]+=1;
        dp[one]+=1;
        long long tot = 0;
        for(int i=1;i<=high;i++)
        {
            if(i-zero>=0) dp[i]=(dp[i-zero]+dp[i])%mod;
            if(i-one>=0) dp[i]=(dp[i-one]+dp[i])%mod;
            if(i>=low) tot = (tot+dp[i])%mod;
        }
        return tot;
    }
};