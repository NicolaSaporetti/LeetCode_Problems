#include <vector>
using namespace std;

class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> v(26,0);
        string r;
        for(auto e : s) v[e-'a']++;
        for(int i=0;i<order.size();i++)
        {
            for(int j=0;j<v[order[i]-'a'];j++) r+=order[i];
            v[order[i]-'a']=0;
        }
        for(int i=0;i<26;i++)
            for(int j=0;j<v[i];j++) r+=char(i+'a');
        return r;
    }
};