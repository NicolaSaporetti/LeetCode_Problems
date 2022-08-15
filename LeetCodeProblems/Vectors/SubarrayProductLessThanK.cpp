#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(!k) return 0;
        int combinations = 0;
        int windowsSize=0;
        int currentValue=1;
        for(int i=0;i<nums.size();i++)
        {
            windowsSize++;
            currentValue*=nums[i];
            if(currentValue>=k)
            {
                for(int j=i-windowsSize+1;j<=i && currentValue>=k;j++)
                {
                    currentValue/=nums[j];
                    windowsSize--;
                }
            }
            combinations+=windowsSize;
        }
        return combinations;
    }
};