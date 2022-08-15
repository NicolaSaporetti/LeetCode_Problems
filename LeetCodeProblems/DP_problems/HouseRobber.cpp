#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> treasure(nums.size()+3, 0);
        treasure[0]=0;
        treasure[1]=0;
        treasure[2]=0;
        for(int i=0;i<nums.size();i++)
        {
            treasure[i+3]= max(treasure[i+1],treasure[i])+nums[i];
        }
        return max(treasure[nums.size()+1],treasure[nums.size()+2]);
    }
};