#include <vector>
using namespace std;

class Solution {
public:
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        sort(begin(nums1),end(nums1));
        sort(begin(nums2),end(nums2));
        for(int i=2;i>=0;i--)
        {
            int v = nums2[0]-nums1[i];
            int k=0;
            int j=i;
            for(;j<nums1.size() && k<nums2.size();j++)
                if(nums1[j]+v==nums2[k]) k++;
            if(k==nums2.size()) return v;
        }
        return -1;
    }
};