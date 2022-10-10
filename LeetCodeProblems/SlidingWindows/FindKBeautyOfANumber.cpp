#include <vector>
using namespace std;

class Solution {
public:
    int divisorSubstrings(int num, int k) {
        int sz = 0;
        int res = 0;
        long long n = num;
        while(n>0)
        {
            sz++;
            n/=10;
        }
        n=num;
        for(int i=0;i<=sz-k;i++)
        {
            long long val = n%static_cast<long long>(pow(10,k));
            if(val!=0 && num%val==0) res++;
            n/=10;
        }
        return res;
    }
};