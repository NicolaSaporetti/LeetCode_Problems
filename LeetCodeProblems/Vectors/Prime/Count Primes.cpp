#include <vector>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if(n<3) return 0;
        vector<bool> v(n,true);
        v[0]=false;
        v[1]=false;
        for (int i=2; i < n; ++i)
        {
            if(!v[i]) continue;
            for(int j=i*i;j<n;j+=i) v[j]=false;
        }
        int r = 0;
        for(auto e : v) r+=e;
        return r;
    }
};