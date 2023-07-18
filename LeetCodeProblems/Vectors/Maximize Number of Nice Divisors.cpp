#include <vector>
using namespace std;

class Solution {
public:
    int maxNiceDivisors(int primeFactors) {
        vector<pair<int,long long>> v(28);
        v[0]={3,3};
        long long start = 1;
        int mod = 1e9+7;
        for(int i=1;i<28;i++)
        {
            v[i].first=v[i-1].first*2;
            v[i].second =(v[i-1].second*v[i-1].second)%mod;
        }
        do
        {
            for(int i=v.size()-1;i>=0;i--)
            {
                if(primeFactors-4>=v[i].first)
                {
                    primeFactors-=v[i].first;
                    start*=v[i].second;
                    start%=mod;
                    break;
                }
            }
        } while(primeFactors>10);
        
        while(primeFactors>4 || primeFactors==3)
        {
            start*=(long long)3;
            start%=mod;
            primeFactors-=3;
        }
        while(primeFactors>=2)
        {
            start*=(long long)2;
            start%=mod;
            primeFactors-=2;
        }
        return start;
    }
};