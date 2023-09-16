#include <vector>
using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int res = INT_MAX;
        int sz = nums.size();
        for(int i=0;i<=sz;i++)
            for(int j=sz;j>=i;j--)
            {
                int c = 0;
                for(int k=0;k<sz;k++)
                {
                    if(k<i && nums[k]!=1) c++;
                    if(k>=j && nums[k]!=3) c++;
                    if(k>=i && k<j && nums[k]!=2) c++;
                }
                res = min(res, c);
            }
        return res;
    }
};