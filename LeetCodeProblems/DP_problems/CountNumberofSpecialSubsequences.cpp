#include <vector>
using namespace std;

class Solution {
public:
    int countSpecialSubsequences(vector<int>& nums) {
        int sz = nums.size();
        int mod = 1e9+7;
        vector<vector<int>> v(3,vector<int>(sz+1,0));
        for(int i=0;i<sz;i++)
        {
            v[0][i+1] = v[0][i];
            if(nums[i]==0) v[0][i+1]=(2*v[0][i]+1)%mod;
        }
        for(int j=1;j<3;j++)
        {
            for(int i=0;i<sz;i++)
            {
                if(nums[i]!=j) v[j][i+1] = v[j][i];
                else v[j][i+1]=(v[j-1][i+1]+(2*v[j][i])%mod)%mod;
            }
        }
        return v[2][sz];
    }
};