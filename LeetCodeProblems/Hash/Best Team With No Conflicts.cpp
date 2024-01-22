#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int,int>> v;
        int sz = scores.size();
        for(int i=0;i<sz;i++)
        {
            v.push_back({ages[i],scores[i]});
        }
        sort(begin(v),end(v));
        map<int,int> pos;
        int res = 0;
        for(int i=sz-1;i>=0;i--)
        {
            auto it = pos.lower_bound(v[i].second);
            if(it==pos.end()) pos[v[i].second] = v[i].second;
            else pos[v[i].second]=it->second+v[i].second;
            res = max(res,pos[v[i].second]);
            it = pos.find(v[i].second);
            while(it!=pos.begin() && prev(it)->second<it->second) pos.erase(prev(it));
        }
        return res;
    }
};