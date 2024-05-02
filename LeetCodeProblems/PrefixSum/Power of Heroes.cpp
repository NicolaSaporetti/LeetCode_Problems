#include <vector>
using namespace std;

class Solution {
public:
    int sumOfPower(vector<int>& nums) {
        sort(begin(nums),end(nums));
        int mod = 1e9+7;
        long long t = nums[0];
        long long r = (((t*t)%mod)*t)%mod;
        int sz = nums.size();
        for(int i=1;i<sz;i++)
        {
            t=(t*2+mod-nums[i-1]+nums[i])%mod;
            r=(((t*(long long)nums[i])%mod)*(long long)nums[i]+r)%mod;
        }
        return r;
    }
};