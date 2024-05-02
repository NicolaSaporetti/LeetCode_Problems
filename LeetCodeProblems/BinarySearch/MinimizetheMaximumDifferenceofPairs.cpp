#include <vector>
using namespace std;

class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(begin(nums),end(nums));
        int minv = 0;
        int maxv = nums.back()-nums[0];
        int r = maxv;
        while(minv<=maxv)
        {
            int avg = (maxv+minv)/2;
            if(canCompute(avg, nums, p))
            {
                r = avg;
                maxv = avg-1;
            }
            else minv = avg+1;
        }
        return r;
    }
private:
    bool canCompute(int avg, vector<int>& nums, int p)
    {
        int n = 0;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i+1]-nums[i]<=avg)
            {
                n++;
                i++;
            }
        }
        return n>=p;
    }
};