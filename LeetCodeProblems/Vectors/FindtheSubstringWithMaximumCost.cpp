#include <vector>
using namespace std;

class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        int r = 0;
        vector<int> v(26,0);
        for(int i=0;i<26;i++) v[i]=i+1;
        for(int i=0;i<chars.size();i++) v[chars[i]-'a']=vals[i];
        int t = 0;
        for(auto e : s)
        {
            t+=v[e-'a'];
            r = max(t,r);
            if(t<0) t=0;
        }
        return r;
    }
};