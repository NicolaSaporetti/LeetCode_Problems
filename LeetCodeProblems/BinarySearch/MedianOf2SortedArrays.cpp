#include <vector>
using namespace std;

class Solution {
private:
    vector<int> fill_sorted_vector(vector<int>& nums1, vector<int>& nums2)
    {
        vector<int> sorted_vector(nums1.size()+nums2.size(),0);
        int nums1_index = 0;
        int nums2_index = 0;
        for(int i=0; i<sorted_vector.size(); i++)
        {
            if(nums2_index>=nums2.size() || (nums1_index<nums1.size() && nums1[nums1_index]<=nums2[nums2_index]))
            {
                sorted_vector[i] = nums1[nums1_index++];
            }
            else
            {
                sorted_vector[i] = nums2[nums2_index++];
            }
        }
        return sorted_vector;
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> sorted_vector = fill_sorted_vector(nums1, nums2);
        return (sorted_vector.size()%2==0)? static_cast<double>(sorted_vector[sorted_vector.size()/2-1]+sorted_vector[sorted_vector.size()/2])/2 : sorted_vector[sorted_vector.size()/2];
    }
};