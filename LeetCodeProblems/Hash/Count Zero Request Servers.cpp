#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        map<int,vector<int>> m;
        map<int,int> active;
        vector<int> r(queries.size(),0);
        for(auto e : logs) m[e[0]].push_back(e[1]);
        for(auto [k,v] : m)
        {
            sort(begin(v),end(v));
            int cur = v[0];
            active[cur]++;
            for(int i=1;i<v.size();i++)
            {
                if(v[i]<=cur+x+1) cur = v[i];
                else
                {
                    active[cur+x+1]--;
                    active[v[i]]++;
                    cur = v[i];
                }
            }
            active[cur+x+1]--;
            cout<<endl;
        }
        vector<pair<int,int>> q1(queries.size());
        for(int i=0;i<queries.size();i++) q1[i]={queries[i],i};
        sort(begin(q1),end(q1));
        auto it = active.begin();
        int serverActive = 0;
        for(int i=0;i<q1.size();i++)
        {
            while(it!=active.end() && q1[i].first>=it->first)
            {
                serverActive+=it->second;
                it++;
            }
            r[q1[i].second]=n-serverActive;
        }
        return r;
    }
};