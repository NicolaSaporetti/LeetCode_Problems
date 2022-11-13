#include <vector>
using namespace std;

class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        int tot=0;
        for(int i=0;i<nums.size();i++)
        {
            int lm = 1;
            for(int j=i;j<nums.size();j++)
            {
                lm=lcm(lm,nums[j]);
                if(lm==k) tot++;
                if(lm>k) break;
            }
        }
        return tot;
    }
};