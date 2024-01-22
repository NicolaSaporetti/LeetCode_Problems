#include <vector>
using namespace std;

class Solution {
public:
    int minimumCoins(vector<int>& prices) {
        int sz = prices.size();
        for(int i=(sz-1)/2-1;i>=0;i--)
        {
            int minv = INT_MAX/2;
            for(int j=1;j<=i+2 && i+j<sz;j++)
            {
                minv=min(prices[i+j],minv);
            }
            prices[i]+=minv;
        }
        return prices[0];
    }
};