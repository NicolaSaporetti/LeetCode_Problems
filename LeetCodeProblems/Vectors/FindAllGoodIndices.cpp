#include <vector>
using namespace std;

class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        vector<int> r;
        int i=k;
        int is=0;
        int ie=k+1;
        if(k==1)
        {
            for(int i=1;i<=nums.size()-2;i++) r.push_back(i);
        }
        else
        {
            while(k+i<nums.size())
            {
                if(nums[is+1]<=nums[is] && nums[ie+1]>=nums[ie])
                {
                    is++;
                    ie++;
                    if(is==i-1) r.push_back(i++);
                }
                else
                {
                    is++;
                    i=is+k;
                    ie=i+1;
                }
            }
        }
        return r;
    }
};