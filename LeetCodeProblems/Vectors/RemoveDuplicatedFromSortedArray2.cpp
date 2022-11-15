#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int sz=nums.size();
        int prev = nums[0];
        int pos = 1;
        int ws=1;
        for(int i=1;i<sz;i++)
        {
            if(nums[i]==prev && ws==1)
            {
                    ws++;
                    nums[pos++]=nums[i];
            }
            else if(nums[i]!=prev)
            {
                ws = 1;
                nums[pos++]=nums[i];
            }
            prev = nums[i];
        }
        nums.resize(pos);
        return pos;
    }
};