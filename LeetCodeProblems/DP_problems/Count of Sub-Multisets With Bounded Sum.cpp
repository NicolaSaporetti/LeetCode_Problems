#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int countSubMultisets(vector<int>& nums, int l, int r) {
        map<int,int> m;
        int mod = 1e9+7;
        vector<int> dp(r+1,0);
        int maxV = 0;
        dp[0]=1;
        for(auto e : nums)
        {
            if(e!=0) m[e]++;
            else dp[0]++;
        }
        for(auto [k,v] : m)
        {
            for(int i=maxV;i>=0;i--)
            {
                for(int j=v;j>=1;j--)
                {
                    int value = j*k;
                    if(value+i>r) continue;
                    dp[i+value]=(dp[i+value]+dp[i])%mod;
                }
            }
            maxV=max(r,maxV+v*k);
        }
        int res = 0;
        for(int i=l;i<=r;i++) res=(res+dp[i])%mod;
        return res;
    }
};