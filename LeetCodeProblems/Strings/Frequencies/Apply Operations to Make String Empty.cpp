#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    string lastNonEmptyString(string s) {
        map<char,int> f;
        map<char,int> m;
        for(int i=0;i<s.size();i++)
        {
            f[s[i]]++;
            m[s[i]]=i;
        }
        int maxE = 0;
        for(auto [k,v] : f) maxE = max(maxE,v);
        vector<pair<int,char>> v1;
        for(auto [k,v] : f)
        {
            if(v==maxE) v1.push_back({m[k],k});
        }
        sort(begin(v1),end(v1));
        string r;
        for(auto e : v1) r+=e.second;
        return r;
    }
};