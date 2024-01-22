#include <set>
#include <queue>
using namespace std;

class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        queue<string> q;
        q.push(s);
        set<string> se;
        int sz = s.size();
        while(!q.empty())
        {
            string ns = q.front();
            q.pop();
            for(int i=1;i<sz;i+=2)
            {
                ns[i]=((ns[i]-'0'+a)%10)+'0';
            }
            string ns1 =ns.substr(sz-b,b)+ns.substr(0,sz-b);
            if(se.find(ns1)==se.end()) q.push(ns1);
            if(se.find(ns)==se.end()) q.push(ns);
            se.insert(ns1);
            se.insert(ns);
        }
        return *se.begin();
    }
};