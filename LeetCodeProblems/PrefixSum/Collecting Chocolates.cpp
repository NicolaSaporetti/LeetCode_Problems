#include <vector>
using namespace std;

class Solution {
public:
    long long minCost(vector<int>& nums, int x) {
        int sz = nums.size();
        vector<long long> v(sz,INT_MAX);
        long long res = 1e18;
        for(int i=0;i<sz;i++)
        {
            long long tot = 0;
            for(int j=0;j<sz;j++)
            {
                v[j]=min(v[j],(long long)nums[(sz+j-i)%sz]);
                tot+=v[j];
            }
            tot+=(long long)x*(long long)i;
            res=min(res,tot);
        }
        return res;
    }
};