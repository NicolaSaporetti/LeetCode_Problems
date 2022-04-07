#include "Financial.hpp"
#include <vector>

using namespace std;

void Financial::simplifyBear(vector<int>& prices)
{
    int newElementPos = 0;
    bool curveIsDescending = false;
    for(int i=0;i<prices.size()-1;i++)
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
    if(!curveIsDescending)
    {
        prices[newElementPos]=prices[prices.size()-1];
        newElementPos++;
    }
    prices.resize(newElementPos);
}

void Financial::simplifyBull(vector<int>& prices)
{
    int newElementPos = 0;
    bool curveIsDescending = true;
    for(int i=0;i<prices.size()-1;i++)
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