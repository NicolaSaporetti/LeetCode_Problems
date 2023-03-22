#include <vector>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& nums) {
        sort(nums.begin(),nums.end(),greater<int>());
        long long tot = 0;
        for(int i=0;i<nums.size();i++)
        {
            tot+=(long long) nums[i];
            if(tot<=0) return i;
        }
        return nums.size();
    }
};