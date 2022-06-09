#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    void checkRotatedArray(vector<int>& nums, int *leftSide, int *rightSide, int target)
    {
        while(nums[*leftSide] == nums[*rightSide] && *leftSide+1<*rightSide)
        {
            *leftSide+=1;
            *rightSide-=1;
        }
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
    bool binarySearch(vector<int>& nums, int leftSide, int rightSide, int target)
    {
        int index = 0;
        if(nums[leftSide]==target || nums[rightSide]==target) return true;
        do
        {
            index=(leftSide+rightSide)/2;
            if(nums[index]== target) return true;
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
        return false;
    }
public:
    bool search(vector<int>& nums, int target) {
        if(nums[0] == target || nums[nums.size()-1] == target) return true;
        int rightSide= nums.size()-1;
        int leftSide=0;
        checkRotatedArray(nums,&leftSide,&rightSide,target);
        return binarySearch(nums,leftSide,rightSide,target);
    }
};