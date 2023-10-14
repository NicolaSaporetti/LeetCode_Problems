#include <vector>
using namespace std;

class Solution {
public:
    int maxSubarrays(vector<int>& nums) {
        int sz = nums.size();
        int v = nums[0];
        for(int i=1;i<sz;i++) v&=nums[i];
        int c = 0;
        int r = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(c==0) c = nums[i];
            else c&=nums[i];
            if(c<=v)
            {
                r++;
                v -= c;
                c=0;
            }
        }
        return r;
    }
};