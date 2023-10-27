#include <vector>
using namespace std;

class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int sz = nums.size();
        int res = INT_MAX;
        vector<int> left(sz+1,INT_MAX);
        vector<int> right(sz+1,INT_MAX);
        for(int i=0;i<sz;i++) left[i+1]=min(nums[i],left[i]);
        for(int i=sz-1;i>=0;i--) right[i]=min(nums[i],right[i+1]);
        for(int i=1;i<sz-1;i++)
        {
            if(nums[i]>left[i] && nums[i]>right[i]) res = min(res, nums[i]+left[i]+right[i]);
        }
        return (res ==INT_MAX)? -1 : res;        
    }
};