#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> findPrimePairs(int n) {
        vector<int> primes = computePrimes(n);
        vector<vector<int>> r;
        for(int i=0;i<primes.size();i++)
        {
            auto it = lower_bound(begin(primes),end(primes),n-primes[i]);
            if(it!=end(primes) && *it+primes[i]==n && primes[i]<=*it) r.push_back({primes[i],*it});
        }
        return r;
    }

    vector<int> computePrimes(int n)
    {
        vector<int> res;
        vector<bool> s(n+1,true);
        for(int i=2;i<n;i++)
        {
            int v = i*2;
            while(v<n)
            {
                s[v]=false;
                v+=i;
            }
        }
        for(int i=2;i<=n;i++) if(s[i]) res.push_back(i);
        return res;
    }
};