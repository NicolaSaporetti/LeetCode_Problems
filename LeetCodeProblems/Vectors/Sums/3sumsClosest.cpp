#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int difference = 20000;
        int result = 0;
        for(int i=0; i< nums.size()-2; i++)
        {
            int k = nums.size()-1;
            int j = i+1;
            while(j<k)
            {
                int sum = nums[i]+nums[j]+nums[k];
                if(abs(sum-target)<difference)
                {
                    difference = abs(sum-target);
                    result = sum;
                }

                if(sum-target >0)
                {
                    k--;
                }
                else{
                    j++;
                }
            }
        }
        return result;
    }
};