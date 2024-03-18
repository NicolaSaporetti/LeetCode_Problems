#include <vector>
using namespace std;

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        vector<int> v;
        v.push_back(-1);
        int r = 0;
        int sz = nums.size();
        for(int i=0;i<sz;i++) if(nums[i]==1) v.push_back(i);
        v.push_back(sz);
        for(int i=1;i+goal<v.size();i++)
        {
            if(goal>0)
            {
                int i1 = v[i+goal]-v[goal+i-1];
                int i2 = v[i]-v[i-1];
                r+=i1*i2;
            }
            else
            {
                int i2 = v[i]-v[i-1];
                r+=(i2*(i2-1)/2);
            }
        }
        return r;
    }
};