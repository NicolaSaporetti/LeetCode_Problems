#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
void simplifyBear(vector<int>& prices)
{
    int newElementPos = 0;
    bool curveIsDescending = false;
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

void simplifyBull(vector<int>& prices)
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
public:
    int wiggleMaxLength(vector<int>& nums) {
        simplifyBear(nums);
        simplifyBull(nums);
        int j=0;
        for(int i=1;i<nums.size() && nums[i]==nums[i-1];i++) j++;
        return nums.size()-j;
    }
};