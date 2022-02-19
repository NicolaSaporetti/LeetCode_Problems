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
public:
    int maxProfit(vector<int>& prices) {
        vector<int> SimplifiedGraph = simplifyBear(prices);
        vector<int> SimplifiedGraph2 = simplifyBull(SimplifiedGraph);
        int profit = 0;
        for(int i=1; i<SimplifiedGraph2.size(); i+=2)
        {
            profit+=SimplifiedGraph2[i]-SimplifiedGraph2[i-1];
        }
        return profit;
    }
};

int main()
{
    vector<int> prices = {2,1};
    Solution solution;
    cout<<solution.maxProfit(prices);
    return 0;
}