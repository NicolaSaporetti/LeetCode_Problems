#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        vector<int> v(target+1,-1);
        v[0]=0;
        for(int j=0;j<nums.size();j++)
            for(int i=target-1;i>=0;i--)
            {
                int e = i+nums[j];
                if(e>target) continue;
                else if(v[i]!=-1) v[e]=max(v[i]+1,v[e]);
            }
        return v[target];
    }
};