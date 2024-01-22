using namespace std;

class Solution {
public:
    int maximumXorProduct(long long a, long long b, int n) {
        int mod = 1e9+7;
        if(b>a) swap(a,b);
        long long i=50;
        for(;i>=0;i--)
        {
            long long mask = ((long long)1<<i);
            if((a&mask) && (b&mask)==0)
            {
                i--;
                break;
            }
            if(n>i && (a&mask)==0 && (b&mask)==0)
            {
                a|=mask;
                b|=mask;
            }
        }
        for(;i>=0;i--)
        {
            if(n>i)
            {
            long long mask = ((long long)1<<i);
                if((a&mask)==0 && (b&mask)==0)
                {
                    a|=mask;
                    b|=mask;
                }
                else if((a&mask) && (b&mask)) continue;
                else
                {
                    a&=~mask;
                    b|=mask;
                }
            }
        }
        return ((a%mod)*(b%mod))%mod;
    }
};