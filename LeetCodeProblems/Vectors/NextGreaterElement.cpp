#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int sz = nums1.size();
        int sz2 = nums2.size();
        vector<int> result(sz,-1);
        for(int i=0;i<sz;i++)
        {
            int idx = find(nums2.begin(),nums2.end(),nums1[i])-nums2.begin();
            //cout<<idx<<endl;
            for(int j=idx+1;j<sz2;j++)
            {
                if(nums2[j]>nums2[idx])
                {
                    result[i]=nums2[j];
                    break;
                }
            }
        }
        return result;
    }
};