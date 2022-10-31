#include <vector>
using namespace std;

class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        if(d>jobDifficulty.size()) return -1;
        vector<vector<int>> dp(d+1,vector<int>(jobDifficulty.size()+1,1000000));
        dp[0][0]=0;
        for(int j=0;j<d;j++)
        {
            for(int i=j;i<jobDifficulty.size();i++)
            {
                int currMax = 0;
                for(int k=i;k<jobDifficulty.size();k++)
                {
                    currMax=max(currMax,jobDifficulty[k]);
                    dp[j+1][k+1] = min(dp[j+1][k+1],dp[j][i]+currMax);
                }
            }
        }
        return dp[d][jobDifficulty.size()];
    }
};