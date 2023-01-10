#include <vector>
using namespace std;

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int tot = 0;
        vector<vector<int>> m(nums1.size()+1,vector<int>(nums2.size()+1,0));
        for(int i=0;i<nums1.size();i++)
        {
            for(int j=0;j<nums2.size();j++)
            {
                if(nums1[i]==nums2[j]) 
                {
                    m[i+1][j+1]=m[i][j]+1;
                    tot=max(tot,m[i+1][j+1]);
                }
            }
        }
        return tot;
    }
};