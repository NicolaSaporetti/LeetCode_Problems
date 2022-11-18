#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> treasure(nums.size()+2, 0);
        for(int i=0;i<nums.size();i++) treasure[i+2]= max(treasure[i+1],treasure[i]+nums[i]);
        return max(treasure[nums.size()],treasure[nums.size()+1]);
    }
};