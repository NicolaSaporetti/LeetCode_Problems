#include <vector>
using namespace std;

class Solution {
public:
    int concatenatedBinary(int n) {
        int res = 0;
        int mod = 1e9+7;
        for(int i=1;i<=n;i++)
        {
            int j=i;
            string s;
            while(j>0)
            {
                s+=(j%2)+'0';
                j/=2;
            }
            for(int i=s.size()-1;i>=0;i--)
            {
                res*=2;
                res+=s[i]-'0';
                res%=mod;
            }
        }
        return res;
    }
};