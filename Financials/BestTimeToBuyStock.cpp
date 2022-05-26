#include <iostream>
#include <stdlib.h>
#include <vector>
#include "Financial.cpp"
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        Financial financial;
        financial.simplifyBear(prices);
        financial.simplifyBull(prices);
        financial.translateValuesToRelative(prices);
        return financial.computeProfit(prices);
    }
};

int main()
{
    vector<int> prices = {5};
    Solution solution;
    cout<<solution.maxProfit(prices);
    return 0;
}