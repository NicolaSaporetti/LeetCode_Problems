#include <vector>
using namespace std;

class Solution {
public:
    int semiOrderedPermutation(vector<int>& nums) {
        int res = 0;
        int posM = min_element(begin(nums),end(nums))-begin(nums);
        for(int i=posM;i>0;i--)
        {
            swap(nums[i],nums[i-1]);
            res++;
        }
        int posMax = max_element(begin(nums),end(nums))-begin(nums);
        for(int i=posMax;i<nums.size()-1;i++)
        {
            swap(nums[i],nums[i+1]);
            res++;
        }
        return res;
    }
};