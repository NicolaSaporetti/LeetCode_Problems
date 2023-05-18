#include <vector>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        bool positionFound=false;
        for(int i=nums.size()-2;i>=0 && !positionFound;i--)
        {
            if(nums[nums.size()-1]>nums[i])
            {
                swap(nums[i],nums[nums.size()-1]);
                sort(nums.begin()+i+1,nums.end());
                positionFound=true;
            }
            else if(nums[i+1]>nums[i])
            {
                swap(nums[i],nums[find_closest_greater_number(nums,i)]);
                sort(nums.begin()+i+1,nums.end());
                positionFound=true;
            }
        }
        if(!positionFound) sort(nums.begin(),nums.end());
    }
    
private:
    int find_closest_greater_number(vector<int>& vec, int index_boundaries)
    {
        int closest_index=0;
        int diff=INT_MAX;
        for(int i=vec.size()-1;i>index_boundaries;i--)
        {
            int temp_diff = vec[i]-vec[index_boundaries];
            if(vec[i]>vec[index_boundaries] && temp_diff<diff)
            {
                diff=temp_diff;
                closest_index=i;
            }
        }
        return closest_index;
    }
};