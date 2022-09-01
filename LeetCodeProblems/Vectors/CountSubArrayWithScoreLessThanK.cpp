#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    public:
    long long countSubarrays(vector<int>& nums, long long k) 
    {
        long long ans=0;
        int i=0,j=0;
        long long sum=0;
        while(j<nums.size())
        {
            sum+=nums[j];
            long long score=sum*(j-i+1);
            while(score>=k)
            {
                sum-=nums[i];
                i++;
                score=sum*(j-i+1);
            }
            ans+=j-i+1;
            j++;
        }
        return ans;
    }
};