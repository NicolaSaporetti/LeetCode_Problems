#include <vector>
#include "BinarySearch.cpp"
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target)
    {
        int index = BinarySearch.search(nums, target);
        if(nums[index]>=target) return index;
        else return index+1;
    }
};