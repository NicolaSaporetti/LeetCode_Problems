#include <vector>
using namespace std;

class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        sort(begin(nums),end(nums));
        long long r = 0;
        int sz = nums.size();
        for(int i=0;i<sz/2;i++)
        {
            if(k<nums[i]) r+=(long long)(nums[i]-k);
        }
        if(nums[sz/2]!=k) r+=(long long)abs(nums[sz/2]-k);
        for(int i=sz/2+1;i<sz;i++)
        {
            if(k>nums[i]) r+=(long long)(k-nums[i]);
        }
        return r;
    }
};