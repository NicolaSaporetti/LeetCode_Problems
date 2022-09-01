#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int value = nums[0];
        int sequences = 1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]-value>k)
            {
                sequences++;
                value=nums[i];
            }
        }
        return sequences;
    }
};