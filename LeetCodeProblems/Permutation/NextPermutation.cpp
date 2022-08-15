#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    void order(vector<int>& vec, int index_boundaries)
    {
        for(int i=index_boundaries+1; i<vec.size()-1; i++)
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
    int find_closest_greater_number(vector<int>& vec, int index_boundaries)
    {
        int closest_index=0;
        int difference=100;
        for(int i=vec.size()-1;i>index_boundaries;i--)
        {
            if(vec[i]>vec[index_boundaries] && vec[i]-vec[index_boundaries]<difference)
            {
                difference=vec[i]-vec[index_boundaries];
                closest_index=i;
            }
        }
        return closest_index;
    }
public:
    void nextPermutation(vector<int>& nums) {
        int temp = 0;
        int numberToSwap = nums.size()-1;
        int i=numberToSwap-1;
        bool positionFound=false;
        if(nums.size()<=1) return;
        for(;i>=0 && !positionFound;i--)
        {
            if(nums[numberToSwap]>nums[i])
            {
                temp = nums[i];
                nums[i]=nums[numberToSwap];
                nums[numberToSwap]=temp;
                positionFound=true;
                order(nums,i);
            }
            else if(nums[i+1]>nums[i])
            {
                temp = nums[i];
                numberToSwap = find_closest_greater_number(nums,i);
                nums[i]=nums[numberToSwap];
                nums[numberToSwap]=temp; 
                positionFound=true;
                order(nums,i);
            }
        }
        if(!positionFound) order(nums,-1);
    }
};