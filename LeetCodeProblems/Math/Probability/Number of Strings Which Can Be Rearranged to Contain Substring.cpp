using namespace std;

class Solution {
public:
    int stringCount(int n) {
        if(n<4) return 0;
        else if(n==4) return 12;
        else 
        {
            int mod = 1e9+7;
            long long res = 1;
            long long res2 = 1;
            long long res3 = 1;
            long long res4 = 1;
            for(int i=0;i<n;i++) res = (res*26)%mod;
            for(int i=0;i<n-1;i++) res2 = (res2*25)%mod;
            res2 = (res2*(n+75))%mod;
            for(int i=0;i<n-1;i++) res3 = (res3*24)%mod;
            res3 = (res3*(2*n+72))%mod;
            for(int i=0;i<n-1;i++) res4 = (res4*23)%mod;
            res4 = (res4*(n+23))%mod;
            return ((res-res2+res3-res4)%mod+mod)%mod;
        }
    }
};