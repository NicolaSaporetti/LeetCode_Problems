using namespace std;

class Solution {
public:
    int countHomogenous(string s) {
        char prev = '0';
        int dim = 0;
        int res = 0;
        int mod = 1e9+7;
        for(auto e : s)
        {
            if(e==prev) dim++;
            else dim = 1;
            res = (res+dim)%mod;
            prev = e;
        }
        return res;
    }
};