#include <iostream>
#include <stdlib.h>
#include <vector>
#include "BinarySearch.cpp"
using namespace std;

class Solution {
private:
    void foundAllNumberInstances(vector<int>& nums, int index, vector<int>& results)
    {
        int i = index;
        while(i-1>=0 && nums[i-1]==nums[index])
        {
            i--;
        }
        results[0]=i;
        i = index;
        while(i+1<nums.size() && nums[i+1]==nums[index])
        {
            i++;
        }
        results[1]=i;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        vector<int> result = {-1,-1};
        BinarySearch binarySearch;
        if(nums.size()!=0)
        {
            int index = binarySearch.search(nums, target);
            if(index!=-1 && nums[index]==target) foundAllNumberInstances(nums,index,result);
        }
        return result;
    }
};

int main()
{
    vector<int> nums = {2,2};
    int target = 3; 
    Solution solution;
    vector<int> result = solution.searchRange(nums,target);
    cout<<result[0]<<" "<<result[1]<<endl;
    return 0;
}