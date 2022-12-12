#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int cz = prices.size();
        int rz = (cz/3)*2+cz%3;
        vector<vector<int>> dp(rz+1, vector<int>(cz+2, 0));
        for(int i=rz-1;i>=0;i--)
        {
            for(int j=cz-1;j>=0;j--)
            {
                int profit_next = dp[i][j+1];
                int profit_buy_sell = ((i%2==1)? dp[i+1][j+2]+prices[j] : dp[i+1][j+1]-prices[j]);
                dp[i][j]=max(profit_next,profit_buy_sell);
            }
        }
        return dp[0][0];
    }
};