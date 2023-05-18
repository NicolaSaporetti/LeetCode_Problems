#include <vector>
using namespace std;

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int minDiv = 1;
        int maxDiv = *max_element(begin(nums),end(nums));
        int res = minDiv;
        while(minDiv<=maxDiv)
        {
            int avg = (maxDiv+minDiv)/2;
            if(isSumLargerThanThreshold(nums,avg,threshold)) minDiv = avg+1;
            else
            {
                res = avg;
                maxDiv= avg-1;
            }
        }
        return res;
    }

private:
    bool isSumLargerThanThreshold(vector<int>& nums, int divisor, int threshold) {
        long long sum = 0;
        for(auto e : nums)
        {
            sum+= (e/divisor);
            sum+= ((e%divisor==0)? 0 : 1);
        }
        return sum>threshold;
    }
};