#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int j=0;
        int maxD = 0;
        int sz2 = nums2.size();
        int sz1 = nums1.size();
        for(int i=0;i<sz1 && i<sz2;i++)
        {
            int j= sz2-(lower_bound(nums2.rbegin(),nums2.rend(),nums1[i])-nums2.rbegin());
            if(j==sz2 || nums2[j]<nums1[i]) j--;
            if(j>=sz2-1)
            {
                if(j>i) maxD = max(maxD,j-i);
                return maxD;
            }
            else if(j>i) maxD = max(maxD,j-i);
        }
        return maxD;
    }
};