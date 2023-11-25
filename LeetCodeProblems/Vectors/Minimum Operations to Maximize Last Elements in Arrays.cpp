#include <vector>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int sz = nums1.size();
        vector<int> nums3 = nums1;
        vector<int> nums4 = nums2;
        int tot = 0;
        int tot2 = 0;
        for(int i=0;i<sz-1;i++)
            if(nums1[i]>nums1[sz-1] || nums2[i]>nums2[sz-1])
            {
                swap(nums1[i],nums2[i]);
                tot++;
            }
        swap(nums3[sz-1],nums4[sz-1]);
        int tot1 = 1;
            for(int i=0;i<sz-1;i++)
            if(nums3[i]>nums3[sz-1] || nums4[i]>nums4[sz-1])
            {
                swap(nums3[i],nums4[i]);
                tot1++;
            }
        if(*max_element(begin(nums1),end(nums1))!=nums1[sz-1] || *max_element(begin(nums2),end(nums2))!=nums2[sz-1]) tot = -1;
        if(*max_element(begin(nums3),end(nums3))!=nums3[sz-1] || *max_element(begin(nums4),end(nums4))!=nums4[sz-1]) tot1 = -1;
        if(tot!=-1 && tot1!=-1) return min(tot,tot1);
        else if(tot==-1) return tot1;
        else if(tot1==-1) return tot;
        else return -1;
    }
};