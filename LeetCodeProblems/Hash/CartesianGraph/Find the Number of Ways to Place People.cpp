#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    int numberOfPairs(vector<vector<int>>& p) {
        int sz = p.size();
        map<int, set<int>> m;
        int r = 0;
        for(auto e : p) m[e[0]].insert(e[1]);
        for(int i=0;i<sz;i++)
        {
            int x = p[i][0];
            int y = p[i][1];
            int ph = INT_MAX;
            for(auto it = m.rbegin();it!=m.rend();it++)
            {
                if(it->first>x) continue;
                else if(it->first==x)
                {
                    auto it2 = it->second.upper_bound(y);
                    if(it2!=it->second.end())
                    {
                        ph = *it2;
                        r++;
                    }
                }
                else
                {
                    auto it2 = it->second.lower_bound(y);
                    if(it2==it->second.end()) continue;
                    if(*it2>=ph) continue;
                    ph=*it2;
                    r++;
                }
            }
        }
        return r;
    }
};