#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int sz=nums.size();
        int j=0;
        for(int i=0;i<sz;i++)
        {
            while(i<sz && nums[i]==0)
            {
                i++;
            }
            if(i<sz) nums[j++] = nums[i];
        }
        for(;j<sz;j++)
        {
            nums[j]=0;
        }
    }
};