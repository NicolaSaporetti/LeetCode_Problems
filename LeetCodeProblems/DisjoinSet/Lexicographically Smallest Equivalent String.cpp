#include <vector>
#include <map>
#include <set>
#include "DisjoinSetUnion.cpp"
using namespace std;

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        DisjoinSetUnion ds(26);
        vector<int> v(26,0);
        map<int,set<int>> m;
        for(int i=0;i<s1.size();i++) ds.connect(s1[i]-'a',s2[i]-'a');
        for(int i=0;i<26;i++)
        {
            m[ds.find_set(i)].insert(i);
            v[i]=i;
        }
        for(auto [k,val] : m)
            for(auto e : val) v[e]=*val.begin();
        for(int i=0;i<baseStr.size();i++)
            baseStr[i]=v[baseStr[i]-'a']+'a';
        return baseStr;
    }
};