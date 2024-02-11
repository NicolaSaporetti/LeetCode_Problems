using namespace std;

class Solution {
public:
    int maximumXorProduct(long long a, long long b, int n) {
        int mod = 1e9+7;
        if(b>a) swap(a,b);
        int v = -1;
        for(int i=50;i>=0;i--)
        {
            long long mask = ((long long)1<<i);
            if(mask&a && !(mask&b))
            {
                v = i;
                break;
            }
        }
        for(int i=n-1;i>=0;i--)
        {
            long long mask = ((long long)1<<i);
            if(!(a&mask) && !(b&mask))
            {
                a|=mask;
                b|=mask;
            }
            else if((a&mask) && !(b&mask) && i!=v)
            {
                b|=mask;
                a&=~mask;
            }
        }
        return ((a%mod)*(b%mod))%mod;
    }
};