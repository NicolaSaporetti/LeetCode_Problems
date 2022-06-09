#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int skipped_elements = 0;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i-1]==nums[i])
            {
                skipped_elements++;
            }
            else
            {
                nums[i-skipped_elements] = nums[i];
            }
        }
        return nums.size()-skipped_elements;
    }
};