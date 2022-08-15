#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        sz = nums.size();
        vector<int> rightSum = fillRightSum(nums);
        if((sz>=2 && !rightSum[1])|| sz==1) return 0;
        for(int i=1;i<sz-1;i++)
        {
            nums[i]+=nums[i-1];
            if(nums[i-1]==rightSum[i+1]) return i;
        }
        if(sz>=2 && !nums[sz-2]) return sz-1;
        return -1;
    }
private:
    vector<int> fillRightSum(vector<int>& nums)
    {
        vector<int> vec(sz,0);
        vec[sz-1]=nums[sz-1];
        for(int i=sz-2;i>=0;i--)
        {
            vec[i]=nums[i]+vec[i+1];
        }
        return vec;
    }
    
    int sz;
};