#include <vector>
using namespace std;

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int res = 0;
        vector<long long> n1(nums.size(),0);
        n1[0]= nums[0];
        for(int i=1;i<nums.size();i++)
        {
            n1[i]=n1[i-1]+nums[i];
        }
        for(int i=0;i<nums.size()-1;i++)
        {
            if(n1[i]>=n1[nums.size()-1]-n1[i]) res++;
        }
        return res;
    }
};