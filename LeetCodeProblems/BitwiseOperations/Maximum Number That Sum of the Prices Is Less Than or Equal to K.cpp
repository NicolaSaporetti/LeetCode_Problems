#include <vector>
using namespace std;

class Solution {
public:
    long long findMaximumNumber(long long k, int x) {
        long long low=0;
        long long high = 1000000000000000;
        long long res = 0;
        while(low<=high)
        {
            long long mid = (high+low)/2;
            if(isBelow(mid,k,x))
            {
                low = mid+1;
                res = mid;
            }
            else high = mid-1;
        }
        return res;
    }
private:
    bool isBelow(long long mid, long long k, int x)
    {
        vector<long long> v(63,0);
        long long res = 0;
        for(long long i=63;i>=0;i--)
        {
            if(((long long)1<<i)&mid)
            {
                for(int j=i-1;j>=0;j--) v[j]+=((long long)1<<(i-1));
                for(int j=i+1;j<63;j++) if(((long long)1<<j)&mid) v[j]+=((long long)1<<i);
            }
        }
        for(long long i=63;i>=0;i--) if(((long long)1<<i)&mid) v[i]++;
        for(int i=0;i<63;i++) if((i+1)%x==0) res+=v[i];
        return res<=k;
    }
};