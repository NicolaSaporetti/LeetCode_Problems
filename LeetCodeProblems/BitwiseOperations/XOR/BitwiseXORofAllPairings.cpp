#include <vector>
using namespace std;

class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()%2==0 && nums2.size()%2==0) return 0;
        else if(nums1.size()%2==0 && nums2.size()%2!=0)
        {
            int res = nums1[0];
            for(int i=1;i<nums1.size();i++)
                res^=nums1[i];
            return res;
        }
        else if(nums1.size()%2!=0 && nums2.size()%2==0)
        {
            int res = nums2[0];
            for(int i=1;i<nums2.size();i++)
                res^=nums2[i];
            return res;
        }
        else
        {
            int res = nums2[0];
            for(int i=1;i<nums2.size();i++)
                res^=nums2[i];
            for(int i=0;i<nums1.size();i++)
                res^=nums1[i];
            return res;
        }
    }
};