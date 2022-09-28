#include <vector>
using namespace std;

class Solution {
public:
    int concatenatedBinary(int n) {
        string finalS;
        for(int i=1;i<=n;i++)
        {
            string temp;
            int j=i;
            while(j>0)
            {
                temp.push_back(j%2+'0');
                j/=2;
            }
            reverse(temp.begin(),temp.end());
            finalS+=temp;
        }
        long long exp=1;
        long long res=0;
        int mod = 1000000007;
        for(int i=finalS.size()-1;i>=0;i--)
        {
            if(finalS[i]=='1') res=(res+exp)%mod;
            exp=(exp*2)%mod;
        }
        return res;
    }
};