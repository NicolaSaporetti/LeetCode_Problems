#include <iostream>
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