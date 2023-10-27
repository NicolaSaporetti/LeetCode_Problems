#include <vector>
using namespace std;

class Solution {
public:
    int numWays(int steps, int arrLen) {
        int sz = min(steps,arrLen);
        int mod = 1e9+7;
        vector<int> v(sz,0);
        v[0]=1;
        for(int i=0;i<steps;i++)
        {
            vector<int> v1(sz,0);
            for(int j=0;j<sz;j++)
            {
                if(j>0) v1[j]=(v1[j]+v[j-1])%mod;
                v1[j]=(v1[j]+v[j])%mod;
                if(j<sz-1) v1[j]=(v1[j]+v[j+1])%mod;
            }
            v = v1;
        }
        return v[0];
    }
};