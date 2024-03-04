#include <vector>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> r;
        int sz = nums.size();
        int j = 0;
        for(int i=0;i<sz;i++)
        {
            if(nums[i]>0)
            {
                r.push_back(nums[i]);
                for(;j<sz;j++)
                    if(nums[j]<0)
                    {
                        r.push_back(nums[j++]);
                        break;
                    }
            }
        }
        return r;
    }
};