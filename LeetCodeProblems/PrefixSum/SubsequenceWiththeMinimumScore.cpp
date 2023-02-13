#include <vector>
using namespace std;

class Solution {
public:
    int minimumScore(string s, string t) {
        sz = s.size();
        vector<int> pref = buildPrefix(s,t);
        vector<int> suf = buildSuffix(s,t);
        int res = max(suf[0],pref[sz-1]);
        for(int i=0;i<sz-1;i++) res = max(res, pref[i]+suf[i+1]);
        return max((int)(t.size()-res),0);
    }
private:
    vector<int> buildPrefix(string& s, string& t)
    {
        vector<int> pref(sz,0);
        int pos = 0;
        for(int i=0;i<sz;i++)
        {
            if(i>0) pref[i]=pref[i-1];
            if(pos<t.size() && s[i]==t[pos])
            {
                pref[i]++;
                pos++;
            }
        }
        return pref;
    }
    vector<int> buildSuffix(string& s, string& t)
    {
        vector<int> suf(sz,0);
        int pos=t.size()-1;
        for(int i=0;i<sz;i++)
        {
            if(i>0) suf[sz-1-i]=suf[sz-i];
            if(pos>=0 && s[sz-1-i]==t[pos])
            {
                suf[sz-1-i]++;
                pos--;
            }
        }
        return suf;
    }
    
int sz;
};