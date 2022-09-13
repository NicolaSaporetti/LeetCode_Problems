#include <vector>
using namespace std;

class Solution {
public:
    int numberOfWays(int startPos, int endPos, int k) {
        int sz = 3001;
        vector<long long> num(sz,0);
        int mod = 1000000007;
        num[startPos+1000]=1;
        for(int i=0;i<k;i++)
        {
            vector<long long> temp(sz,0);
            for(int j=1;j<sz-1;j++)
            {
                temp[j+1]+=num[j];
                temp[j-1]+=num[j];
            }
            for(int j=0;j<sz;j++)
            {
                num[j]=temp[j]%mod;
            }
        }
        return num[1000+endPos];
    }
};