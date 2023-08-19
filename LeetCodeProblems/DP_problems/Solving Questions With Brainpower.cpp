#include <vector>
using namespace std;

class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int sz=questions.size();
        vector<long long> dp(sz+1,0);
        for(int i=sz-1;i>=0;i--)
        {
            if(questions[i][1]+i+1>=sz) dp[i]=max(dp[sz]+questions[i][0],dp[i+1]);
            else dp[i]=max(dp[i+questions[i][1]+1]+questions[i][0],dp[i+1]);
        }
        return dp[0];
    }
};