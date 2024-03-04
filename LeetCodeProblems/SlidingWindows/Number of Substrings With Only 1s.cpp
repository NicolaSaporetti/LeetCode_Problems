using namespace std;

class Solution {
public:
    int numSub(string s) {
        int start = 0;
        int res = 0;
        int mod =  1e9+7;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='0') start = i+1;
            else
            {
                res=(res+i-start+1)%mod;
            }
        }
        return res%mod;
    }
};