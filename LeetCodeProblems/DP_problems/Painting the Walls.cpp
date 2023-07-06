#include <vector>
using namespace std;

class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int sz = cost.size();
        vector<int> dp(sz+1,-1);
        for(int i=0;i<sz;i++)
        {
            for(int j=sz-1;j>=2;j--)
            {
                if(dp[j]!=-1)
                {
                    int newPainted = min(sz,j+time[i]+1);
                    int newCost = dp[j]+cost[i];
                    if(dp[newPainted]!=-1) dp[newPainted]=min(dp[newPainted],newCost);
                    else dp[newPainted] = newCost;
                }
            }
            int newPainted = min(sz,time[i]+1);
            if(dp[newPainted]!=-1) dp[newPainted]=min(dp[newPainted],cost[i]);
            else dp[newPainted] = cost[i];
        }
        return dp[sz];
    }
};