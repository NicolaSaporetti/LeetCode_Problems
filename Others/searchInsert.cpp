#include <iostream>
#include <stdlib.h>
#include <vector>
#include "BinarySearch.cpp"
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target)
    {
        BinarySearch binarySearch;
        int index = binarySearch.search(nums, target);
        if(nums[index]>=target) return index;
        else return index+1;
    }
};

int main()
{
    vector<int> nums = {0,1,3};
    int target = 4; 
    Solution solution;
    cout<<solution.searchInsert(nums,target)<<endl;
    return 0;
}