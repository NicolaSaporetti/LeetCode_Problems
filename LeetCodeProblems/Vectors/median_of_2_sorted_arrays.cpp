#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    void fill_sorted_vector(vector<int>& nums1, vector<int>& nums2, vector<int>& dest)
    {
        int nums1_index = 0;
        int nums2_index = 0;
        for(int i=0; i<dest.size(); i++)
        {
            if(nums2_index>=nums2.size() || (nums1_index<nums1.size() && nums1[nums1_index]<=nums2[nums2_index]))
            {
                dest[i] = nums1[nums1_index];
                nums1_index++;
            }
            else
            {
                dest[i] = nums2[nums2_index];
                nums2_index++;
            }
        }
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> sorted_vector;
        double median = 0;

        sorted_vector.resize(nums1.size()+nums2.size());
        fill_sorted_vector(nums1, nums2, sorted_vector);
        if(sorted_vector.size()%2==0)
        {
            median = (sorted_vector[sorted_vector.size()/2-1]+sorted_vector[sorted_vector.size()/2])/2;
        }
        else
        {
            median = sorted_vector[sorted_vector.size()/2];
        }
        return median;
    }
};