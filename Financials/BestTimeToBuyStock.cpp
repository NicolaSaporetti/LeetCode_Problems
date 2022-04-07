#include <iostream>
#include <stdlib.h>
#include <vector>
#include "Financial.cpp"
using namespace std;

class Solution {
private:
    void translateValuesToRelative(vector<int>& prices)
    {
        for(int i=prices.size()-1;i>0;i--)
        {
            prices[i] = prices[i]-prices[i-1];
        }
        prices[0] = 0;
        for(int i=0;i<prices.size();i++)
        {
            cout<<prices[i]<<" ";
        }
        cout<<endl;
    }
public:
    int maxProfit(vector<int>& prices) {
        Financial financial;
        financial.simplifyBear(prices);
        for(int i=0;i<prices.size();i++)
        {
            cout<<prices[i]<<" ";
        }
        cout<<endl;
        financial.simplifyBull(prices);
        for(int i=0;i<prices.size();i++)
        {
            cout<<prices[i]<<" ";
        }
        cout<<endl;
        translateValuesToRelative(prices);
        
        int maxProfit = 0;
        int profit = 0;
        for(int i=1; i<prices.size(); i++)
        {
            profit+=prices[i];
            if(maxProfit<profit) maxProfit=profit;
            if(profit<=0)
            {
                profit=0;
            }
        }
        return maxProfit;
    }
};

int main()
{
    vector<int> prices = {};
    Solution solution;
    cout<<solution.maxProfit(prices);
    return 0;
}