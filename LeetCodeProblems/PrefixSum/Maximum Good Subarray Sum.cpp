#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<long long, long long> m;
        long long k1 = k;
        long long r = -100000000000000000;
        int sz = nums.size();
        vector<long long> v(sz+1,0);
        for(int i=0;i<sz;i++) v[i+1]=v[i]+(long long)nums[i];
        for(int i=0;i<sz;i++)
        {
            long long v1 = nums[i];
            if(m.count(v1+k1)>0)
            {
                int e = m[v1+k1];
                r = max(r,v[i+1]-v[e]);
            }
            if(m.count(v1-k1)>0)
            {
                int e = m[v1-k1];
                r = max(r,v[i+1]-v[e]);
            }
            if(m.count(v1)==0) m[v1]=i;
            else
            {
                int e = m[v1];
                if(v[i]-v[e]<0) m[v1]=i;
            }
        }
        return (r==-100000000000000000) ? 0 : r;
    }
};