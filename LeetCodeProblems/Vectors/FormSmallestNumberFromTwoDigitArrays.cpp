#include <vector>
using namespace std;

class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        sort(begin(nums1),end(nums1));
        nums1.erase(unique(begin(nums1),end(nums1)),end(nums1));
        sort(begin(nums2),end(nums2));
        nums2.erase(unique(begin(nums2),end(nums2)),end(nums2));
        int res = 0;
        if(nums1[0]<nums2[0]) res= nums1[0]*10+nums2[0];
        else res= nums2[0]*10+nums1[0];
        int i=0;
        int j=0;
        while(i<nums1.size() && j<nums2.size())
        {
            if(nums1[i] == nums2[j]) return nums1[i];
            else if(nums1[i]>nums2[j]) j++;
            else i++;
        }
        return res;
    }
};