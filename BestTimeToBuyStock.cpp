#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

class Solution {
private:
    vector<int> simplifyBear(vector<int>& prices)
    {
        vector<int> SimplifiedGraph;
        bool maxFound = false;
        for(int i=0;i<prices.size()-1;i++)
        {
            if(prices[i+1]>prices[i])
            {
                SimplifiedGraph.push_back(prices[i]);
                maxFound = true;
            }
            else if(maxFound == true)
            {
                SimplifiedGraph.push_back(prices[i]);
                maxFound = false;
            }
        }
        SimplifiedGraph.push_back(prices[prices.size()-1]);
        return SimplifiedGraph;
    }
    vector<int> simplifyBull(vector<int>& prices)
    {
        vector<int> SimplifiedGraph;
        bool maxFound = false;
        SimplifiedGraph.push_back(prices[0]);
        for(int i=1;i<prices.size();i++)
        {
            if(prices[i]<prices[i-1])
            {
                SimplifiedGraph.push_back(prices[i-1]);
                maxFound = true;
            }
            else if(maxFound == true)
            {
                SimplifiedGraph.push_back(prices[i-1]);
                maxFound = false;
            }
        }
        SimplifiedGraph.push_back(prices[prices.size()-1]);
        return SimplifiedGraph;
    }
    vector<int> translateValuesToRelative(vector<int>& prices)
    {
        vector<int> SimplifiedGraph;
        SimplifiedGraph.resize(prices.size());
        for(int i=prices.size()-2;i>=0;i--)
        {
            SimplifiedGraph[i+1] = prices[i+1]-prices[i];
        }
        SimplifiedGraph[0] = 0;
        return SimplifiedGraph;
    }
public:
    int maxProfit(vector<int>& prices) {
        vector<int> SimplifiedGraph = simplifyBear(prices);
        vector<int> SimplifiedGraph2 = simplifyBull(SimplifiedGraph);
        vector<int> SimplifiedGraph3 = translateValuesToRelative(SimplifiedGraph2);
        
        int maxProfit = 0;
        int profit = 0;
        for(int i=1; i<SimplifiedGraph3.size(); i++)
        {
            profit+=SimplifiedGraph3[i];
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
    vector<int> prices = {7,1,5,3,6,4};
    Solution solution;
    cout<<solution.maxProfit(prices);
    return 0;
}