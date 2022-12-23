#include <vector>
using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int sz = nums.size();
        vector<int> v2 = nums;
        sort(v2.begin(),v2.end());
        int ls = sz;
        int rs = 0;
        for(int i=0;i<sz;i++)
        {
            if(nums[i]!=v2[i])
            {
                ls = i;
                break;
            }
        }
        for(int i=sz-1;i>=0;i--)
        {
            if(nums[i]!=v2[i])
            {
                rs = i;
                break;
            }
        }
        return max(rs-ls+1,0);
    }
};