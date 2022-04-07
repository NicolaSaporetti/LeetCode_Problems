#include "BinarySearch.hpp"
#include <vector>

using namespace std;

int BinarySearch::search(vector<int>& nums, int target)
{
    int index = 0;
    int leftSide = 0;
    int rightSide = nums.size()-1;
    do
    {
        index=(leftSide+rightSide)/2;
        if(nums[index]== target) return index;
        else{
            if(nums[index]>target)
            {
                rightSide=index-1;
            }
            else{
                leftSide=index+1;
            }
        }
    } while (leftSide<=rightSide);
    return -1;
}