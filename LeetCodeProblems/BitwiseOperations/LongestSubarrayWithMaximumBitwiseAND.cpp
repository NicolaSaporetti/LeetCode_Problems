#include <vector>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int m = *max_element(nums.begin(),nums.end());
        int v = 0;
        int res = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==m)
            {
                v++;
                res=max(res,v);
            }
            else v = 0;
        }
        return res;
    }
};