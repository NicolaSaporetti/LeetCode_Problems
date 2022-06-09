#include <iostream>
#include <vector>
#include "Financial.cpp"
using namespace std;

class Solution { 
public:
    int maxProfit(vector<int>& prices) {
        Financial financial;
        financial.simplifyBear(prices);
        financial.simplifyBull(prices);
        int profit = 0;
        for(int i=1; i<prices.size(); i+=2)
        {
            profit+=prices[i]-prices[i-1];
        }
        return profit;
    }
};

int main()
{
    vector<int> prices = {7,1,5,3,6,4};
    Solution solution;
    cout<<solution.maxProfit(prices)<<endl;
    return 0;
}