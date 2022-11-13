#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res = fill_sorted_vector(nums1, nums2);
        return (res.size()%2==0)? static_cast<double>(res[sorted_vector.size()/2-1]+res[res.size()/2])/2 : res[res.size()/2];
    }

private:
    vector<int> fill_sorted_vector(vector<int>& nums1, vector<int>& nums2)
    {
        int sz1 = nums1.size();
        int sz2 = nums2.size();
        vector<int> sorted_vector(sz1+sz2);
        int idx1 = 0;
        int idx2 = 0;
        for(int i=0; i<sz1+sz2; i++)
        {
            if(idx2>=sz2 || (idx1<sz1 && nums1[idx1]<=nums2[idx2])) sorted_vector[i] = nums1[idx1++];
            else sorted_vector[i] = nums2[idx2++];
        }
        return sorted_vector;
    }
};