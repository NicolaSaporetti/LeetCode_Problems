#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    int sz;
    int computeTSum(vector<int>& nums, int divisor) {
        long long sum = 0;
        for(int i=0;i<sz;i++)
        {
            if(nums[i]>=divisor) sum+= (nums[i]/divisor);
            if(nums[i]%divisor!=0) sum++;
        }
        return sum;
    }
    
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        sz = nums.size();
        sort(nums.begin(),nums.end());
        int minDiv = 1;
        int maxDiv = nums[sz-1];
        int result = (minDiv+maxDiv)/2;
        int tempsum = 0;
        while(minDiv<maxDiv)
        {
            tempsum = computeTSum(nums,result);
            if(tempsum<=threshold)
            {
                maxDiv= result;
            }
            else
            {
                minDiv = result+1;
            }
            result = (minDiv+maxDiv)/2;
        }
        return result;
    }
};