#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int arraySign(vector<int>& nums) {
        bool isPositive = true;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0) return 0;
            else if(nums[i]<0) isPositive = !isPositive;
        }
        if(isPositive) return 1;
        else return -1;
    }
};