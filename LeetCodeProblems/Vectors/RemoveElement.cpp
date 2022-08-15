#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int j=0;
        for(int i=0; i<nums.size();i++)
        {
            if(nums[i]==val)
            {
            }
            else{
                nums[j]=nums[i];
                j++;
            }
        }
        nums.resize(j+1);
        return j;
    }
};