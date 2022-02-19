#include <./Headers/Financial.hpp>
#include <vector>

using namespace std;

vector<int> Financial::simplifyBear(vector<int>& prices)
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
}

vector<int> Financial::simplifyBull(vector<int>& prices)
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