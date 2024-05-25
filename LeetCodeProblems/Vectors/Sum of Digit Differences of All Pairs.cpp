#include <vector>
using namespace std;

class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        vector<vector<long long>> v(10,vector<long long>(10));
        for(auto e : nums)
        {
            int i=0;
            while(e>0)
            {
                v[i][e%10]++;
                e/=10;
                i++;
            }
        }
        long long r = 0;
        for(int i=0;i<10;i++)
            for(int j=0;j<10;j++)
                for(int z=0;z<10;z++)
                {
                    if(z==j) continue;
                    r+=v[i][j]*v[i][z];
                }
        return r/2;    
    }
};