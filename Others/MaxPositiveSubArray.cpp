#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int tempSum=0;
        int max=-20000;
        for(int i=0;i<nums.size();i++)
        {
            tempSum+=nums[i];
            if(max<=tempSum) max=tempSum;
            if(tempSum<=0) tempSum=0;
        }
        return max;
    }
};

int main()
{
    Solution solution;
    return 0;
}