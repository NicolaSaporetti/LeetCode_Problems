#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> solution;
        bool found = false;
        for(int i=0; i< nums.size() && found == false; i++)
        {
            for(int j=i+1; j< nums.size() && found == false; j++)
            {
                if(nums[i]+nums[j]==target)
                {
                    solution.push_back(i);
                    solution.push_back(j);
                    found = true;
                }
            }
        }
        return solution;
    }
};