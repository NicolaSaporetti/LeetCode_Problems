#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(begin(events),end(events));
        vector<map<int,int>> v(k+1);
        v[0][0]=0;
        for(int i=0;i<k;i++)
        {
            v[i+1][0]=0;
            for(auto& e : events)
            {
                auto it = v[i+1].upper_bound(e[1]);
                auto it2 = v[i].lower_bound(e[0]);
                int nv = max(prev(it)->second,prev(it2)->second+e[2]);
                if(prev(it2)->second+e[2]>prev(it)->second)
                {
                    v[i+1][e[1]]=nv;
                    auto it3=v[i+1].find(e[1]);
                    while(next(it3)!=v[i+1].end() && it3->second>=next(it3)->second) v[i+1].erase(next(it3));
                }
            }
        }
        int res = 0;
        for(auto& [key,a] : v[k]) res = max(res,a);
        return res;
    }
};