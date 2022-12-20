#include <vector>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int sz = nums.size();
        int num = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=i+1)
            {
                int val = nums[i];
                nums[i]=-1;
                while(val>0 && val<=sz && nums[val-1]!=val)
                {
                    swap(val,nums[val-1]);
                }
            }
        }
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==-1)
            {
                num = i+1;
                break;
            }
        }
        if(num==0) num=sz+1;
        return num;   
    }
};