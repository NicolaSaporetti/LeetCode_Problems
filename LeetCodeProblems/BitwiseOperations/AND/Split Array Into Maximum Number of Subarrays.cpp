#include <vector>
using namespace std;

class Solution {
public:
    int maxSubarrays(vector<int>& nums) {
        int v = nums[0];
        for(int i=1;i<nums.size();i++) v&=nums[i];
        int val = -1;
        int r = 0;
        for(int i=0;i<nums.size();i++)
        {
            val&=nums[i];
            if(val==v)
            {
                r++;
                v-=val;
                val = -1;
            }
        }
        return r;
    }
};