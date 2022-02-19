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

    int computeProfit(vector<int>& graph, int startPos, int endPos)
    {
        int min = graph[startPos];
        int max = 0;
        int profit = 0;
        int localmin = graph[startPos];
        int i = startPos;
        do
        {
            bool exit = false;
            for(int j=i+1; j<=endPos; j++)
            {
                if(graph[j]-graph[i]>profit)profit = graph[j]-graph[i];
            }
            while (i<endPos && exit == false)
            {
                if(graph[i]>=localmin) i++;
                else
                {
                    localmin = graph[i];
                    exit = true;
                }
            }
            
        } while (i<endPos);
        return profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        vector<int> SimplifiedGraph = simplifyBear(prices);
        vector<int> SimplifiedGraph2 = simplifyBull(SimplifiedGraph);
        int maxprofit = 0;
        for(int i=0;i<SimplifiedGraph2.size()-1;i+=2)
        {
            int profit = computeProfit(SimplifiedGraph2,0,i+1);
            if(i+2<SimplifiedGraph2.size()-1) profit+= computeProfit(SimplifiedGraph2,i+2,SimplifiedGraph2.size()-1);
            if(profit>maxprofit) maxprofit = profit;
        }
        return maxprofit;
    }
};

int main()
{
    vector<int> prices = {3,3,5,0,0,3,1,4};
    Solution solution;
    cout<<solution.maxProfit(prices);
    return 0;
}