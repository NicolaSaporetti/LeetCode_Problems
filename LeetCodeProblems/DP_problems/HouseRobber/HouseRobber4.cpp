#include <vector>
using namespace std;

class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int minV = *min_element(begin(nums),end(nums));
        int maxV = *max_element(begin(nums),end(nums));
        int val = maxV;
        while(minV<=maxV)
        {
            int avg = minV+(maxV-minV)/2;
            if(canSteal(avg,nums,k))
            {
                val = avg;
                maxV = avg-1;
            }
            else minV = avg+1;
        }
        return val;
    }
private:
    bool canSteal(int avg, vector<int>& nums, int k)
    {
        for(int i=0;i<nums.size() && k>0;i++)
        {
            if(nums[i]<=avg)
            {
                k--;
                i++;
            }
        }
        return k<=0;
    }
};