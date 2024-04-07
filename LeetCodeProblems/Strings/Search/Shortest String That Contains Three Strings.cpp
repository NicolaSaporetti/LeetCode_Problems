#include <map>
#include <set>
using namespace std;

class Solution {
public:
    string minimumString(string a, string b, string c) {
        map<int,set<string>> m;
        string s0 = concat(a,b,c);
        m[s0.size()].insert(s0);
        s0 = concat(a,c,b);
        m[s0.size()].insert(s0);
        s0 = concat(b,a,c);
        m[s0.size()].insert(s0);
        s0 = concat(b,c,a);
        m[s0.size()].insert(s0);
        s0 = concat(c,a,b);
        m[s0.size()].insert(s0);
        s0 = concat(c,b,a);
        m[s0.size()].insert(s0);
        return *m.begin()->second.begin();
    }
private:
    string concat(string& a, string& b, string& c)
    {
        string s = concat(a,b);
        return concat(s,c);
    }
    string concat(string& a, string& b)
    {
        if(a.find(b)!=std::string::npos) return a;
        int sz1 = a.size();
        int sz2 = b.size();
        string res;
        for(int i=0;i<sz1;i++)
        {
            bool canConcat = true;
            for(int j=0;i+j<sz1 && j<sz2 && canConcat;j++)
            {
                if(a[i+j]!=b[j]) canConcat = false;
            }
            if(canConcat) return a.substr(0,i)+b;
        }
        return a+b;
    }
};