#include <vector>
using namespace std;

class Solution {
public:
    long long minEnd(int n, int x) {
        n--;
        long long r = x;
        int re = 1;
        for(long long i=0;i<50 && n>0;i++)
        {
            if(!((1LL<<i)&r))
            {
                if(n%2==1) r|=(1LL<<i);
                n/=2;
            }
        }
        return r;
    }
};