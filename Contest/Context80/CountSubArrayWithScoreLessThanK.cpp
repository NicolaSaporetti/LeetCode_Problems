#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    long long result;
    long long start;
    long long prevI;
    long long cumulative_sum;
    long long i;

    void updateResult()
    {
        if(prevI>=start)
        {
            result-=((prevI-start)*(prevI-start+1)/2);
        }
        result+=((i-start)*(i-start+1)/2);
    }

    void findNewValidSubArray(long long res)
    {
        if(res<=cumulative_sum)
        {
            updateResult();
            prevI = i;
            while(res<=cumulative_sum)
            {
                cumulative_sum-=nums[start];
                start++;
                if(i>=start)
                {
                    res = k/(i-start+1);
                    if(k%(i-start+1)!=0) res++;
                }
                else res = k;
            }
        }
    }

public:
    long long countSubarrays(vector<int>& nums, long long k) {
        result =0;
        start = 0;
        prevI = -1;
        cumulative_sum = 0;
        i = 0;
        for(i=0;i<nums.size();i++)
        {
            cumulative_sum+=nums[i];
            long long res = k/(i-start+1);
            if(k%(i-start+1)!=0) res++;
            findNewValidSubArray(res);
        }
        updateResult();
        return result;
    }
};