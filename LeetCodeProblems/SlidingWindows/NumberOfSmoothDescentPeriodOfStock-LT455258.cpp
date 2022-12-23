#include <vector>
using namespace std;

class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long res = 1;
        long long ws=1;
        int sz = prices.size();
        for(int i=1;i<sz;i++)
        {
            if(prices[i]!=prices[i-1]-1) ws=0;
            ws++;
            res+=ws;
        }
        return res;
    }
};