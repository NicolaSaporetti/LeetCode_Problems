#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

class Solution {
private:
    void checkRotatedArray(vector<int>& nums, int *leftSide, int *rightSide, int target)
    {
        if(nums[*leftSide] > nums[*rightSide])
        {
            int index=0;
            while((nums[*leftSide] > nums[*rightSide]) && *leftSide+1<*rightSide)
            {
                index=(*leftSide+*rightSide)/2;
                if(nums[*rightSide] < nums[index])
                {
                    *leftSide=index;
                }
                else{
                    *rightSide=index;
                }
            }
            if(target<nums[0])
            {
                *leftSide=*rightSide;
                *rightSide=nums.size()-1;
            }
            else{
                *rightSide=*leftSide;
                *leftSide=0;
            }
        }
    }
    int binarySearch(vector<int>& nums, int leftSide, int rightSide, int target)
    {
        int index = 0;
        if(nums[leftSide]==target) return leftSide;
        if(nums[rightSide]==target) return rightSide;
        do
        {
            index=(leftSide+rightSide)/2;
            if(nums[index]== target) return index;
            else{
                if(nums[index]>target)
                {
                    rightSide=index;
                }
                else{
                    leftSide=index;
                }
            }
        } while (leftSide+1<rightSide);
        return -1;
    }
public:
    int search(vector<int>& nums, int target) {
        int rightSide= nums.size()-1;
        int leftSide=0;
        checkRotatedArray(nums,&leftSide,&rightSide,target);
        return binarySearch(nums,leftSide,rightSide,target);
    }
};

int main()
{
    vector<int> nums = {1,3};
    int target = 3; 
    Solution solution;
    cout<<solution.search(nums,target)<<endl;
    return 0;
}