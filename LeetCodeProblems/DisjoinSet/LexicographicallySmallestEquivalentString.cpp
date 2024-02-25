#include <vector>
#include "DisjoinSet.cpp"
using namespace std;

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        DisjoinSet ds(26);
        vector<int> v(26,0);
        for(int i=0;i<26;i++) v[i]=i;
        for(int i=0;i<s1.size();i++) ds.connect(s1[i]-'a',s2[i]-'a');
        for(int i=0;i<s1.size();i++)
        {
            v[s1[i]-'a']=ds.find_root(s1[i]-'a');
            v[s2[i]-'a']=ds.find_root(s2[i]-'a');
        }
        for(int i=0;i<baseStr.size();i++) baseStr[i]=v[baseStr[i]-'a']+'a';
        return baseStr;
    }
};