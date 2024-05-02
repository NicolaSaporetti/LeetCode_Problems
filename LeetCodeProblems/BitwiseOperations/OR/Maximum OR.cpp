#include <vector>
using namespace std;

class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
        long long r = 0;
        vector<int> v(30,0);
        for(int i=0;i<nums.size();i++)
            for(int j=0;j<30;j++) if((1<<j)&nums[i]) v[j]++;
        for(long long e : nums)
        {
            long long t = 0;
            for(int j=0;j<30;j++)
            {
                if((1LL<<j)&e) v[j]--;
                if(v[j]) t|=(1<<j);
            }
            e<<=k;
            t|=e;
            r = max(r,t);
            e>>=k;
            for(int j=0;j<30;j++) if((1LL<<j)&e) v[j]++;
        }
        return r;
    }
};