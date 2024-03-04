#include <vector>
using namespace std;

class Solution {
public:
    bool winnerSquareGame(int n) {
        dp.assign(n+1,-1);
        dp[0]=0;
        return compute(n);
    }
private:
    bool compute(int n)
    {
        if(dp[n]!=-1) return dp[n];
        else
        {
            bool res = false;
            for(int i=1;i*i<=n;i++) res|=!(compute(n-i*i));
            return dp[n]=res;
        }
    }
    
    vector<int> dp;
};