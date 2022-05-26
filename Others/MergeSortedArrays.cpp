#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> temp1;
        temp1.resize(m);
        for(int i=0;i<m;i++)
        {
            temp1[i]=nums1[i];
        }
        int i=0;
        int j=0;
        for(;i<m && j<n;)
        {
            if(temp1[i]<nums2[j])
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
        for(;i<m;i++)
        {
            nums1[i+j] = temp1[i];
        }
        for(;j<n;j++)
        {
            nums1[i+j] = nums2[j];
        }
    }
};

int main()
{
    return 0;
}