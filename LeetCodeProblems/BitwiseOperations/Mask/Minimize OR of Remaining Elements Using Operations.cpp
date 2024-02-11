#include <vector>
using namespace std;

class Solution {
public:
    int minOrAfterOperations(vector<int>& nums, int k) {
        int r = 0;
        int mask = 0;
        int sz = nums.size();
        for(int i=30;i>=0;i--)
        {
            mask|= (1<<i);
            int val = -1;
            int tot = 0;
            for(int j=0;j<sz;j++)
            {
                if(nums[j]&mask)
                {
                    tot++;
                    val&=nums[j];
                }
                else val = -1;
                if((val&mask)==0)
                {
                    tot--;
                    val = -1;
                }
            }
            if(tot>k)
            {
                r|=(1<<i);
                mask&=~(1<<i);
            }
        }
        return r;
    }
};