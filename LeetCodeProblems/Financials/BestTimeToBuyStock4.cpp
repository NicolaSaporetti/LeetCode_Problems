#include <vector>
using namespace std;


class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        if (k == 0 || prices.size() == 0 || prices.size() == 1) return 0;
        vector<vector<int>> dp(k + 1, vector<int>(prices.size()));
        
        for (int i = 1; i < dp.size(); i++)
        {
            for (int j = 1; j < dp[i].size(); j++)
            {
                int x;
                int mx = INT_MIN;
                for (int k = 0; k < j; k++)
                {
                    x = prices[j] - prices[k] + dp[i - 1][k];
                    mx = max(x, mx);
                }
                dp[i][j] = max(dp[i][j - 1], mx);
            }
        }
        return dp[dp.size() - 1][prices.size() - 1];
    }
};