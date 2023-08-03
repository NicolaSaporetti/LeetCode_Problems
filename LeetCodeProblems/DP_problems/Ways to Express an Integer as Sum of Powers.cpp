#include <vector>
using namespace std;

class Solution {
public:
    int numberOfWays(int n, int x) {
        mod = 1e9+7;
        dp.assign(n+1,vector<int>(n+1,-1));
        int maxIndex = 1;
        while(pow(maxIndex,x)<=n) maxIndex++;
        return solve(1,n,maxIndex,x);
    }

private:
    int solve(int ind ,int n ,int maxIndex , int x){
        if(n == 0) return 1;
        if(n < 0) return 0;
        if(ind == maxIndex) return 0;
        if(dp[ind][n] != -1) return dp[ind][n];

        int nonpick = solve(ind+1,n,maxIndex,x)%mod;
        int pick = solve(ind+1,n-pow(ind,x),maxIndex,x)%mod;

        return dp[ind][n] = (pick + nonpick)%mod;
    }

    int mod;
    vector<vector<int>> dp;
};