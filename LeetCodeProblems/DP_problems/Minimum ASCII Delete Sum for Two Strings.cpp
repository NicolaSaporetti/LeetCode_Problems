#include <vector>
using namespace std;

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int rz = s1.size();
        int cz = s2.size();
        int tot = 0;
        for(auto& e : s1) tot+=e;
        for(auto& e : s2) tot+=e;
        vector<vector<int>> dp(rz+1,vector<int>(cz+1,0));
        for(int i=0;i<rz;i++)
        {
            for(int j=0;j<cz;j++)
            {
                if(s1[i]==s2[j]) dp[i+1][j+1]=dp[i][j]+s1[i];
                else dp[i+1][j+1]=max(dp[i+1][j],dp[i][j+1]);
            }
        }
        return tot-2*dp[rz][cz];
    }
};