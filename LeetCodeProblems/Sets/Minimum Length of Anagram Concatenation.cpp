#include <map>
#include <set>
using namespace std;

class Solution {
public:
    int minAnagramLength(string s) {
        map<char,int> m;
        int sz = s.size();
        for(auto e : s) m[e]++;
        set<int> div;
        for(int j=1;j<=sz;j++) if(sz%j==0) div.insert(j);
        auto it = div.begin();
        for(auto e : div)
        {
            bool isCor = true;
            for(int j=0;j<sz/e && isCor;j++)
            {
                map<int,int> m1;
                for(int i=0;i<e;i++) m1[s[j*e+i]]++;
                for(auto [k,v] : m) if(m1.count(k)==0 || m1[k]!=v/(sz/e)) isCor = false;
            }
            if(isCor) return e;
        }
        return sz;
    }
};