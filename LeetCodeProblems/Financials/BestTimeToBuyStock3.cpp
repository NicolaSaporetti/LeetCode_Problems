#include <iostream>
#include <vector>
#include "Financial.cpp"
using namespace std;

class Solution {
private:
void compute_part1(vector<int>& output, vector<int>& relative_prices)
{
    int price = 0;
    for(int i=1;i<relative_prices.size(); i++)
    {
        price+=relative_prices[i];
        if(price<0) price=0;
        output[i]=max(output[i-1],price);
    }
}
void compute_part2(vector<int>& output, vector<int>& relative_prices)
{
    int price = 0;
    int maxPrice = 0;
    for(int i=relative_prices.size()-2;i>=0; i--)
    {
        price+=relative_prices[i+1];
        if(price<0) price=0;
        if(price>maxPrice) maxPrice=price;
        output[i]=max(output[i+1],price);
    }
}
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit=0;
        Financial financial;
        financial.simplifyBear(prices);
        financial.simplifyBull(prices);
        financial.translateValuesToRelative(prices);
        vector<int> part1(prices.size(),0);
        vector<int> part2(prices.size(),0);
        compute_part1(part1,prices);
        if(part2.size()>=2) compute_part2(part2,prices);
        for(int i=0;i<part1.size();i++)
        {
            maxProfit=max(maxProfit,part1[i]+part2[i]);
        }
        return maxProfit;
    }
};

int main()
{
    vector<int> prices = {2,1,4,5,2,9,7};
    Solution solution;
    cout<<solution.maxProfit(prices);
    return 0;
}