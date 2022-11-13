#include <vector>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<bool>> dp(n+1, vector<bool>(m+1,false));
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(i==0 && j==0) dp[i][j]=true;
                else if(i==0)
                {
                    if(p[j-1]=='*') dp[i][j]=dp[i][j-1];
                }
                else if(j==0) dp[i][j]=false;
                else
                {
                    if(s[i-1]==p[j-1] || p[j-1]=='?')
                    {
                        dp[i][j]=dp[i-1][j-1];
                    }
                    else if(p[j-1]=='*')
                    {
                        dp[i][j]= dp[i][j-1] | dp[i-1][j];
                    }
                }
            }
        }
        return dp[n][m];
    }
};