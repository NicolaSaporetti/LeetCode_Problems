#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int findRotateSteps(string ring, string key) {
        map<char,vector<pair<int,int>>> m;
        int sz = ring.size();
        for(int i=0;i<sz;i++) m[ring[i]].push_back({i,0});
        for(auto& e : m[key[0]]) e.second = min(e.first,sz-e.first);
        for(int i=1;i<key.size();i++)
        {
            for(auto&e : m[key[i]])
            {
                int t = INT_MAX;
                for(auto&e1 : m[key[i-1]]) t = min(t,e1.second+min(abs(e1.first-e.first),sz-abs(e1.first-e.first)));
                e.second = t;
            }
        }
        int r = INT_MAX;
        for(auto& e : m[key.back()])r = min(e.second,r);
        return r+key.size();
    }
};