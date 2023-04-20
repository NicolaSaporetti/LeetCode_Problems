#include <vector>
using namespace std;

class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int sz = nums.size();
        int res = 0;
        for(int i=0;i<sz-3;i++)
            for(int j=i+1;j<sz-2;j++)
                for(int z=j+1;z<sz-1;z++)
                    for(int k=z+1;k<sz;k++)
                        if(nums[i]+nums[j]+nums[z]==nums[k]) res++;
        return res;
    }
};