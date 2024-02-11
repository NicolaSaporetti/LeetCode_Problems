#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int countPairs(vector<vector<int>>& coordinates, int k) {
       map<pair<int,int>,long long> m;
       for(auto e : coordinates) m[{e[0],e[1]}]++;
       int r = 0;
       if(k==0)
       {
            for(auto [ke,v] : m) r+=v*(v-1)/2;
            return r;
       }
       else
       {
            for(int i=0;i<=k;i++)
            {
                for(auto [ke,v] : m)
                {
                    int v1 = ke.first^i;
                    int v2 = (k-i)^ke.second;
                    auto it = m.find({v1,v2});
                    if(it!=m.end()) r+=v*it->second;
                }
            }
            return r/2;
       }
    }
};