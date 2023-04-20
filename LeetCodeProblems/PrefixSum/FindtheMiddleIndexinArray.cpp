#include <vector>
using namespace std;

class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        vector<int> sum(nums.size()+1,0);
        for(int i=0;i<nums.size();i++)
        {
            sum[i+1]=nums[i]+sum[i];
        }
        for(int i=0;i<nums.size();i++)
        {
            if(sum[i]==sum[nums.size()]-sum[i+1]) return i;
        }
        return -1;
    }
};