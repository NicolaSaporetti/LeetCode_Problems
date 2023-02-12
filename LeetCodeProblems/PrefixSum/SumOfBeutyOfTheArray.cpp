#include <vector>
using namespace std;

class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int sum = 0;
        int sz = nums.size();
        vector<int> smaller(sz,0);
        vector<int> greater(sz);
        smaller[0]=nums[0];
        for(int i=1;i<sz;i++) smaller[i]=max(nums[i],smaller[i-1]);
        greater[sz-1]=nums[sz-1];
        for(int i=sz-2;i>=0;i--) greater[i]=min(nums[i],greater[i+1]);
        for(int i=1;i<sz-1;i++)
        {
            if(smaller[i-1]<nums[i] && greater[i+1]>nums[i]) sum+=2;
            else if(nums[i-1]<nums[i] && nums[i]<nums[i+1]) sum+=1;
        }
        return sum;
    }
};