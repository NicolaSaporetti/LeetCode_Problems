#include <vector>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int sz = nums.size();
        for(int i=0;i<sz;i++)
        {
            int el = nums[i];
            nums[i]=-1;
            while(el<sz+1 && el>0 && nums[el-1]!=el) swap(nums[el-1],el);
        }
        for(int i=0;i<sz;i++) if(nums[i]==-1) return i+1;
        return sz+1;
    }
};