#include <vector>
using namespace std;

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int tot = 0;
        vector<vector<int>> m(nums1.size()+1,vector<int>(nums2.size()+1,0));
        for(int i=nums1.size()-1;i>=0;i--)
        {
            for(int j=nums2.size()-1;j>=0;j--)
            {
                if(nums1[i]==nums2[j]) 
                {
                    m[i][j]=m[i+1][j+1]+1;
                    tot=max(tot,m[i][j]);
                }
            }
        }
        return tot;
    }
};