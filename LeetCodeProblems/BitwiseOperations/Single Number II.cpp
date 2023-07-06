#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> b(32,0);
        for(long long n : nums)
        {
            for(int i=0;i<32 && n;i++)
            {
                b[i]+=n%2;
                n/=2;
            }
        }
        long long v = 1;
        int result =0;
        for(int i=0;i<32;i++)
        {
            b[i]%=3;
            if(b[i]==1 || b[i]==-2) result+=v;
            else if(b[i]==2 || b[i]==-1) result-=v;
            v*=2;
        }
        return result;
    }
};