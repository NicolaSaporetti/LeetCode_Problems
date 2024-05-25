#include <vector>
using namespace std;

class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(begin(nums),end(nums));
        int r = 0;
        int mod = 1e9+7;
        vector<int> pow;
        pow.push_back(1);
        for(int i=1;i<=nums.size();i++) pow.push_back((pow.back()*2)%mod);
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]*2>target) break;
            int pos = upper_bound(begin(nums),end(nums),target-nums[i])-begin(nums);
            r = (r+pow[pos-i-1])%mod;
        }
        return r;
    }
};