#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        int res = 0;
        int mod = 1e9+7;
        int sz = nums.size();
        for(int i=1;i<nums.size();i++) nums[i]+=nums[i-1];
        for(int i=0;i<nums.size()-2;i++)
        {
            int maxDif = nums[i]+(nums.back()-nums[i])/2;
            int pos1 = lower_bound(begin(nums)+i+1,end(nums),2*nums[i])-begin(nums);
            int pos = upper_bound(begin(nums)+pos1,begin(nums)+sz-1,maxDif)-begin(nums)-1;
            if(pos>=pos1) res=(res+(pos-pos1+1))%mod;
        }
        return res;
    }
};