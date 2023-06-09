using namespace std;

class Solution {
public:
    long long minimumCost(string s) {
        long long sz = s.size();
        long long st = 0;
        long long e = sz-1;
        long long res = 0;
        while(st+1<sz && s[st+1]==s[st]) st++;
        while(e-1>=0 && s[e-1]==s[e]) e--;
        while(st<e)
        {
            long long c1 = st+1;
            long long c2 = sz-e;
            if(c1<=c2)
            {
                st++;
                while(st+1<sz && s[st+1]==s[st]) st++;
                res+=c1;
            }
            else
            {
                e--;
                while(e-1>=0 && s[e-1]==s[e]) e--;
                res+=c2;
            }
        }
        return res;
    }
};