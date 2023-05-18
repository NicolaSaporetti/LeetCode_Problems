#include <vector>
using namespace std;

class Solution {
public:
    int help(int prev2,int prev1,int idx,int sz){
        if(idx==sz) return 1;
        if(dp[prev2][prev1][idx]!=-1) return dp[prev2][prev1][idx];
        int ans=0;
        for(int cur=1;cur<=6;cur++){
            if(cur!=prev2 && cur!=prev1 && (prev1==0 or __gcd(cur,prev1)==1)){
                ans=(ans+help(prev1,cur,idx+1,sz))%1000000007;
            }
        }
        return dp[prev2][prev1][idx]=ans;
        
    }

    int distinctSequences(int n) {
        dp.resize(7);
        for(int i=0;i<7;i++)
        {
            dp[i].assign(7,vector<int>(10005,-1));
        }
        return help(0,0,0,n);
    }

private:
    vector<vector<vector<int>>> dp;
};