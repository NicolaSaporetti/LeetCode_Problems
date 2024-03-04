#include <vector>
using namespace std;

class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(begin(nums),end(nums));
        int r = 1;
        int len = 1;
        int start = 0;
        bool increase = false;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i-1]==nums[i]) increase = true;
            else if(nums[i-1]+1==nums[i]) len++;
            else if(nums[i-1]+2==nums[i] && increase)
            {
                len+=2;
                increase = false;
            }
            else
            {
                r = max(r, len+increase+compPrev(nums,start));
                for(int j=start;j<i;j++) nums[j]++;
                start = i;
                len = 1;
                increase = false;
            }
        }
        r = max(r, len+increase+compPrev(nums,start));
        return r;
    }
private:
    int compPrev(vector<int>& nums,int ind)
    {
        int len = 0;
        for(int i=ind;i>=1;i--)
        {
            if(nums[i-1]==nums[i]) continue;
            else if(nums[i-1]+1==nums[i]) len++;
            else break;
        }
        return len;
    }
};