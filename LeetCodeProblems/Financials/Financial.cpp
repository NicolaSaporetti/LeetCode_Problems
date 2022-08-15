#include "Financial.hpp"
#include <vector>
using namespace std;

void Financial::simplifyBear(vector<int>& prices)
{
    int newElementPos = 0;
    bool curveIsDescending = true;
    for(int i=0;prices.size()>1 && i<prices.size()-1;i++)
    {
        if(prices[i]<prices[i+1])
        {
            prices[newElementPos++]=prices[i];
            curveIsDescending = false;
        }
        else
        {
            if(!curveIsDescending)
            {
                prices[newElementPos++]=prices[i];
                curveIsDescending = true;
            }
        }
    }
    prices[newElementPos]=prices[prices.size()-1];
    newElementPos++;
    prices.resize(newElementPos);
}

void Financial::simplifyBull(vector<int>& prices)
{
    int newElementPos = 0;
    bool curveIsDescending = true;
    for(int i=0;prices.size()>1 && i<prices.size()-1;i++)
    {
        if(prices[i]>prices[i+1])
        {
            prices[newElementPos++]=prices[i];
            curveIsDescending = true;
        }
        else
        {
            if(curveIsDescending)
            {
                prices[newElementPos++]=prices[i];
                curveIsDescending = false;
            }
        }
    }
    prices[newElementPos++]=prices[prices.size()-1];
    prices.resize(newElementPos);
}

void Financial::translateValuesToRelative(vector<int>& prices)
{
    for(int i=prices.size()-1;i>0;i--)
    {
        prices[i] = prices[i]-prices[i-1];
    }
    prices[0] = 0;
}

int Financial::computeProfit(vector<int>& relative_prices)
{
    int maxProfit = 0;
    int profit = 0;
    for(int i=1; i<relative_prices.size(); i++)
    {
        profit+=relative_prices[i];
        if(maxProfit<profit) maxProfit=profit;
        if(profit<=0)
        {
            profit=0;
        }
    }
    return maxProfit;
}