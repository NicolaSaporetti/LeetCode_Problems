#include <vector>
using namespace std;

class Solution {
public:
    long long minimumCost(string s) {
        if(s.size()==1) return 0;
        long long sz = s.size();
        vector<long long> dp(sz);
        for(long long i=1;i<sz;i++)
        {
            if(s[i]!=s[i-1]) dp[i]=dp[i-1]+i;
            else dp[i]=dp[i-1];
        }
        vector<long long> dpi(sz);
        for(int i=sz-2;i>=0;i--)
        {
            if(s[i]!=s[i+1]) dpi[i]=dpi[i+1]+sz-1-i;
            else dpi[i]=dpi[i+1];
        }
        long long res = 100000000000000;
        for(int i=0;i<sz-1;i++)
        {
            if(dp[i]!=dp[i+1]) res = min(res,dp[i]+dpi[i]);
            else res = min(dp[i]+dpi[i+1],res);
        }
        return res;
    }
};