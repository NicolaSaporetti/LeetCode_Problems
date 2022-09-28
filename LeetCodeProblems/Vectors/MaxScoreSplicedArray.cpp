#include <vector>
using namespace std;

class Solution {
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        sz = nums1.size();
        diff.assign(sz,0);
        for(int i=0;i<sz;i++)
        {
            diff[i]=nums1[i]-nums2[i];
        }
        int res1 = computeVal(nums2);
        for(int i=0;i<sz;i++) diff[i] = -diff[i];
        int res2 = computeVal(nums1);
        return max(res1,res2);
    }
    
private:
    int computeVal(vector<int>& nums)
    {
        int res = 0;
        int finalM = 0;
        int maxV = 0;
        for(int i=0;i<sz;i++)
        {
            res+=nums[i];
            maxV+=diff[i];
            if(maxV<=0) maxV = 0;
            else
            {
                finalM = max(finalM,maxV);
            }
        }
        return res+finalM;
    }
    
    vector<int> diff;
    int sz;
};