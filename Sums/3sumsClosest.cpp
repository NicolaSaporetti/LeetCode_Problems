#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
    private:
    void order(vector<int>& vec)
    {
        for(int i=0; i< vec.size(); i++)
        {
            for(int j=i+1; j< vec.size(); j++)
            {
                if(vec[i]>vec[j])
                {
                    int temp = vec[j];
                    vec[j] = vec[i];
                    vec[i] = temp;
                }
            }
        }
    }
public:
    int threeSumClosest(vector<int>& nums, int target) {
        order(nums);
        for(int i=0; i< nums.size(); i++) cout<<nums[i]<<endl;
        int difference = 2000;
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