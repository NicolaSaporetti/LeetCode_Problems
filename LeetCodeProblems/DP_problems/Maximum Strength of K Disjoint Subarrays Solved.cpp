#include <vector>
using namespace std;

class Solution {
public:
    long long maximumStrength(vector<int>& nums, int k) {
        int sz= nums.size();
        vector<vector<long long>> v(k+1,vector<long long>(sz+1,0));
        long long sign = 1;
        long long n = 1;
        for(int i=k-1;i>=0;i--)
        {
            v[k-n][sz-n]=(long long)(nums[sz-n]*n*sign)+v[k-n+1][sz-n+1];
            for(int j=sz-n-1;j>=i;j--)
            {
                v[k-n][j]=(long long)(nums[j]*n*sign)+max(v[k-n+1][j+1],v[k-n][j+1]);
            }
            for(int j=sz-n-1;j>=i;j--) v[k-n][j]=max(v[k-n][j],v[k-n][j+1]);
            sign*=-1;
            n++;
        }
        return v[0][0]; 
    }
};