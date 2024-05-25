#include <vector>
using namespace std;

long long binpowWithModulo(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res%m;
}

class Solution {
public:
    vector<int> findProductsOfElements(vector<vector<long long>>& queries) {
        vector<int> r;
        for(auto e : queries)
        {
            pair<long long,long long> low = compute(e[0]);
            pair<long long,long long> high = compute(e[1]+1);
            long long t = computeLeft(high.second,high.first+1)-computeLeft(low.second,low.first+1)+computeNumberPower2(high.first)-computeNumberPower2(low.first);
            r.push_back(binpowWithModulo(2,t,e[2]));
        }
        return r;
    }
private:
    pair<long long,long long> compute(long long v)
    {
        long long mi = 1;
        long long ma=1000000000000000LL;
        long long r = mi;
        long long left = 0;
        while(mi<=ma)
        {
            long long avg = (ma+mi)/2;
            long long n= isGreater(avg);
            if(n<=v)
            {
                r = avg;
                mi = avg+1;
                left = v-n; 
            }
            else ma = avg-1;
        }
        return {r,left};
    }
    long long isGreater(long long v)
    {
        long long n = 0;
        for(long long i=60;i>=0;i--)
        {
            long long mask = (1LL<<i);
            if(v&mask)
            {
                n+=(v-mask+1)+(mask>>1)*i;
                v&=~mask;
            }
        }
        return n;
    }
    long long computeNumberPower2(long long v)
    {
        long long n = 0;
        for(long long i=60;i>=1;i--)
        {
            long long mask = (1LL<<i);
            if(v&mask)
            {
                n+=(v-mask+1)*i;
                for(int j=i-1;j>=1;j--) n+=(mask>>1)*j;
                v&=~mask;
            }
        }
        return n;
    }
    long long computeLeft(long long left, long long n)
    {
        long long r = 0;
        for(int i=0;i<60 && left>0;i++)
        {
            if((1LL<<i)&n)
            {
                r+=i;
                left--;
            }
        }
        return r;
    }
};