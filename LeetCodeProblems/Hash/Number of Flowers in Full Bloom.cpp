#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
        map<int,vector<int>> m;
        vector<int> res(persons.size(),0);
        int n = 0;
        for(int i=0;i<persons.size();i++) m[persons[i]].push_back(i);
        map<int,int> f;
        for(auto e : flowers)
        {
            f[e[0]]++;
            f[e[1]+1]--;
        }
        sort(begin(persons),end(persons));
        auto it = f.begin();
        for(auto [k,v] : m)
        {
            while(it!=f.end() && it->first<=k)
            {
                n+=it->second;
                it++;
            }
            for(auto& el : v) res[el]=n;
        }
        return res;
    }
};