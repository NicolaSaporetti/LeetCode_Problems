#include <vector>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> results;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int j=0;
        for(int i=0, j=0;i<nums1.size() && j<nums2.size();)
        {
            if(nums1[i]==nums2[j])
            {
                results.push_back(nums1[i]);
                i++;
                j++;
            }
            else if(nums1[i]<nums2[j]) i++;
            else j++;
        }
        return results;
    }
};