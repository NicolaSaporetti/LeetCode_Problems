#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    int sz;
    
    bool divideBags(vector<int>& nums, int value, int operations) {
        for(int i=sz-1;i>=0 && operations>=0;i--)
        {
            if(nums[i]>value)
            {
                operations-=(nums[i]/value);
                if(nums[i]%value==0) operations++;
            }
            else if(nums[i]<=value) break;
        }
        return (operations<0)? false : true;
    }
    
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        sz = nums.size();
        sort(nums.begin(),nums.end());
        int minV = 1;
        int maxV = nums[sz-1];
        while(minV<maxV)
        {
            int value = (minV+maxV)/2;
            bool valueObtained = divideBags(nums,value,maxOperations);
            if(!valueObtained)
            {
                minV = value+1;
            }
            else
            {
                maxV= value;
            }
        }
        return minV;
    }
};