#include <vector>
using namespace std;

class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int res = 0;
        mask.assign(31,0);
        wz=0;
        for(int i=0;i<nums.size();i++)
        {
            wz++;
            int temp = nums[i];
            for(int i=0;i<31 && temp>0;i++)
            {
                mask[i]+=temp%2;
                temp/=2;
            }
            shrinkWindowsTillIsValid(nums, i);
            res = max(res, wz);
        }
        return res;
    }
    
private:
    void shrinkWindowsTillIsValid(vector<int>& nums, int current)
    {
        bool valid = true;
        do
        {
            valid = true;
            for(int j=0;j<31;j++)
                if(mask[j]>=2)
                {
                    valid = false;
                    break;
                }
            if(!valid)
            {
                wz--;
                int temp = nums[current-wz];
                for(int j=0;j<31 && temp>0;j++)
                {
                    mask[j]-=temp%2;
                    temp/=2;
                }
            }
        } while(!valid);
    }
    
    vector<int> mask;
    int wz;
};