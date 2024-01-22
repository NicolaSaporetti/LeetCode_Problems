#include <vector>
using namespace std;

class Solution {
public:
    int numberOfWays(string corridor) {
        int sz = corridor.size();
        int seats=0;
        long long res = 1;
        long long plants = 1;
        int mod = 1e9+7;
        for(int i=0;i<sz;i++)
        {
            if(corridor[i]=='S') seats++;
            if(seats==2 && corridor[i]=='P') plants++;
            if(seats>2) 
            {
                res=(res*plants)%mod;
                seats=1;
                plants=1;
            }
        }
        if(seats!=2) return 0;
        else return res;
    }
};