#include <vector>
#include <map>
#include <set>
using namespace std;

class Solution {
public:
    string minimumString(string a, string b, string c) {
        map<int,set<string>> res;
        string fin = concat(a,concat(b,c));
        res[fin.size()].insert(fin);
        fin = concat(a,concat(c,b));
        res[fin.size()].insert(fin);
        fin = concat(b,concat(a,c));
        res[fin.size()].insert(fin);
        fin = concat(b,concat(c,a));
        res[fin.size()].insert(fin);
        fin = concat(c,concat(a,b));
        res[fin.size()].insert(fin);
        fin = concat(c,concat(b,a));
        res[fin.size()].insert(fin);
        return *res.begin()->second.begin();
    }
private:
    string concat(string a, string b)
    {
        int sza = a.size();
        int szb = b.size();
        size_t found = a.find(b);
        if (found != string::npos) return a;
        found = b.find(a);
        if (found != string::npos) return b;
        for(int i=min(sza,szb);i>=1;i--)
        {
            if(a.substr(sza-i,i)==b.substr(0,i))
            {
                return a+b.substr(i,szb-i);
            }
        }
        return a+b;
    }
};