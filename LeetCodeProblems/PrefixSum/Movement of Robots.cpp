#include <vector>
using namespace std;

class Solution {
public:
    int sumDistance(vector<int>& nums, string s, int d) {
        vector<long long> r;
        int mod = 1e9+7;
        long long sz = nums.size();
        for(int i=0;i<sz;i++)
        {
            if(s[i]=='L') r.push_back((long long)nums[i]-(long long)d);
            else r.push_back((long long)nums[i]+(long long)d);
        }
        sort(begin(r),end(r));
        long long tot = 0;
        for(auto e : r) tot+=e;
        long long res = 0;
        for(int i=0;i<r.size()-1;i++)
        {
            tot-=r[i];
            res=(res+tot-(long long)(sz-i-1)*r[i])%mod;
        }
        return res;
    }
};