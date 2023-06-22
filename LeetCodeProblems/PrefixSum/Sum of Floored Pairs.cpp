#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int sumOfFlooredPairs(vector<int>& nums) {
        int mx = *max_element(begin(nums),end(nums));
        int mn = *min_element(begin(nums),end(nums));
        vector<long long> freq(mx+1,0);
        map<int,long long> m;
        int mod = 1e9+7;
        int res = 0;
        for(auto& e : nums) m[e]++;
        for(auto& [key,val] : m)
        {
            for(int i=key;i<=mx;i+=key)
            {
                freq[i]+=val;
            }
        }
        for(int i=mn+1;i<=mx;i++) freq[i]=(freq[i]+freq[i-1]);
        for(auto& [key,val] : m)
        {
            res = (res+val*freq[key])%mod;
        }
        return res;
    }
};