#include <vector>
using namespace std;

class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        long long minv = 1;
        long long maxv = 1e14;
        long long res = maxv;
        while(minv<=maxv)
        {
            long long avg = (minv+maxv)/2;
            if(compute(avg,coins)>=k)
            {
                maxv = avg-1;
                res = avg;
            }
            else minv = avg+1;
        }
        return res;
    }
    long long compute(long long avg, vector<int>& coins)
    {
        long long tot = 0;
        for(int i=1;i<(1<<coins.size());i++)
        {
            long long lcv =1;
            for(int j=0;j<coins.size();j++)
            {
                if((1<<j)&i)
                {
                    lcv = lcm(lcv,coins[j]);
                }
            }
            if(__builtin_popcount(i)%2) tot+=(avg/lcv);
            else tot-=(avg/lcv);
        }
        return tot;
    }
};