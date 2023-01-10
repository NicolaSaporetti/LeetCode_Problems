#include <vector>
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ws=0;
        int result = 0;
        int currentValue=1;
        for(int i=0;i<nums.size();i++)
        {
            ws++;
            currentValue*=nums[i];
            if(currentValue>=k)
            {
                while(currentValue>=k && ws>0)
                {
                    currentValue/=nums[i-ws+1];
                    ws--;
                }
            }
            result+=ws;
        }
        return result;
    }
};