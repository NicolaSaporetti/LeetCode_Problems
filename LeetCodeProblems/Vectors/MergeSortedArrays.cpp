#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> temp1(m);
        for(int i=0;i<m;i++) temp1[i]=nums1[i];
        for(int i=0,j=0;i<m || j<n;)
        {
            if(j>=n || (i<m && temp1[i]<nums2[j]))
            {
                nums1[i+j] = temp1[i];
                i++;
            }
            else
            {
                nums1[i+j] = nums2[j];
                j++;
            }
        }
    }
};