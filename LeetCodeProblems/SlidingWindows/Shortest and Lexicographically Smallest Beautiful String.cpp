#include <set>
using namespace std;

class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int sz = s.size();
        int st = 0;
        int n = 0;
        int l = 0;
        int ml = INT_MAX;
        set<string> s1;
        for(int i=0;i<sz;i++)
        {
            if(s[i]=='1') n++;
            if(n>k)
            {
                st++;
                n--;
            }
            if(n==k)
            {
                while(s[st]=='0')st++;
                ml=min(ml,i-st+1);
            }
        }
        for(int i=0;i<=sz-ml;i++)
        {
            int n=0;
            for(int j=0;j<ml;j++) if(s[j+i]=='1') n++;
            if(n==k) s1.insert(s.substr(i,ml));
            
        }
        return (s1.empty())? "" : *s1.begin();
    }
};