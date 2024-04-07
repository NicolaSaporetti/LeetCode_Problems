#include <vector>
using namespace std;

class Solution {
public:
    bool checkArray(vector<int>& nums, int k) {
        int sz = nums.size();
        vector<int> v(sz+1);
        int p = 0;
        for(int i=0;i<sz-k+1;i++)
        {
            p+=v[i];
            if(nums[i]<p) return false;
            if(nums[i]>p)
            {
                v[i+k]-=nums[i]-p;
                p = nums[i];
            }
        }
        for(int i=sz-k+1;i<sz;i++)
        {
            p+=v[i];
            if(nums[i]!=p) return false;
        }
        return true;
    }
};