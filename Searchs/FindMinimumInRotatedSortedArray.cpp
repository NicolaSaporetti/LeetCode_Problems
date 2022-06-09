#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int index = 0;
        int leftSide = 0;
        int rightSide = nums.size()-1;
        do
        {
            index=(leftSide+rightSide)/2;            
            if(nums[index]<nums[rightSide])
            {
                rightSide=index;
            }
            else{
                leftSide=index+1;
            }
        } while (leftSide<rightSide);
        return nums[rightSide];
    }
};