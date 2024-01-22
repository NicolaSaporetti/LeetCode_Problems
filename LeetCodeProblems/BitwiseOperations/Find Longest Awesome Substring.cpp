#include <map>
using namespace std;

class Solution {
public:
    int longestAwesome(string s) {
        int r = 0;
        int mask = 0;
        map<int,int> m;
        m[0]=0;
        for(int j=0;j<s.size();j++)
        {
            int p = s[j]-'0';
            mask^=(1<<p);
            if(m.count(mask)==0) m[mask]=j+1;
            else r = max(r,j+1-m[mask]);
            for(int i=0;i<10;i++)
            {
                int mask2 = mask^(1<<i);
                auto it = m.find(mask2);
                if(it!=m.end()) r = max(r, j+1-it->second);
            }
        }
        return r;
    }
};