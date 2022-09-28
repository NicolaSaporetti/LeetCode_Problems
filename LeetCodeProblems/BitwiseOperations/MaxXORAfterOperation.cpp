#include <vector>
using namespace std;

class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        vector<bool> v(31,false);
        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<31;j++)
            {
                if(nums[i]&1<<j) v[j]= true;
            }
        }
        int res = 0;
        for(int j=30;j>=0;j--)
        {
            res*=2;
            if(v[j]>0) res+=1;
        }
        return res;
    }
};