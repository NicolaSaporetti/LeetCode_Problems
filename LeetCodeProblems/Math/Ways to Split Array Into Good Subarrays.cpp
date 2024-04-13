#include <vector>
using namespace std;

class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        bool one = false;
        long long zero = 1;
        int res = 1;
        if(count_if(begin(nums),end(nums),[](int ele){return ele==1;})==0) return 0;
        int mod = 1e9+7;
        int i=0;
        while(i<nums.size() && nums[i]!=1) i++;
        for(;i<nums.size();i++)
        {
            if(nums[i]==1)
            {
                res=(res*zero)%mod;
                zero = 1;
            }
            else zero++;
        }
        return res;
    }
};