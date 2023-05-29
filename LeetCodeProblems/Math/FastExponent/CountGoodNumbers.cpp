using namespace std;

class Solution {
public:
    int countGoodNumbers(long long n) {
        mod = 1e9+7;
        long long v1 = fast_exp(5,(n+1)/2);
        long long v2 = fast_exp(4,n/2);
        return (v1*v2)%mod;
    }
private:
    int fast_exp(long long num, long long exp)
    {
        if(exp==0) return 1;
        long long y = 1;
        while(exp>1)
        {
            if(exp%2==0)
            {
                num = (num*num)%mod;
                exp/=2;
            }
            else
            {
                y = (y*num)%mod;
                num = (num*num)%mod;
                exp = (exp-1)/2;
            }
        }
        y = (y*num)%mod;
        return y;
    }

    int mod;
};