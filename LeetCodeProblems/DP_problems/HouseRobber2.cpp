#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()<=3)
        {
            if(nums.size()==1) return nums[0];
            else if(nums.size()==2) return max(nums[0],nums[1]);
            else return max(nums[0],max(nums[1],nums[2]));
        }
        vector<int> treasure(nums.size()+1, 0);
        treasure[2]=nums[1];
        treasure[3]=nums[2];
        for(int i=3;i<nums.size();i++)
        {
            treasure[i+1]= max(treasure[i-1],treasure[i-2])+nums[i];
        }
        treasure[1]=nums[0];
        for(int i=2;i<nums.size()-1;i++)
        {
            treasure[i+1]= max(max(treasure[i-1],treasure[i-2])+nums[i],treasure[i+1]);
        }
        return max(max(treasure[nums.size()],treasure[nums.size()-1]),treasure[nums.size()-2]);
    }
};