#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        string r;
        map<char,int> m;
        for(auto c : s) m[c]++;
        map<int,vector<char>> f;
        for(auto [k,v] : m) f[v].push_back(k);
        for(auto it = f.rbegin();it!=f.rend();it++)
        {
            for(auto e : it->second)
                for(int i=0;i<it->first;i++) r+=e;
        }
        return r;
    }
};
