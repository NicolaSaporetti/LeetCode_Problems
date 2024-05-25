#include <vector>
#include <priority_queue>
#include ""
using namespace std;

class Solution {
public:
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        vector<int> s = dijkstra(0,n,edges);
        int t = s[n-1];
        vector<int> d = dijkstra(n-1,n,edges);
        vector<bool> r(edges.size(),true);
        for(int i=0;i<n;i++) if(s[i]+d[i]==t) r[i]=true;
        vector<vector<pair<int,int>>> g(n);
        for(int i=0;i<edges.size();i++)
        {
            g[edges[i][0]].push_back({edges[i][1],i});
            g[edges[i][1]].push_back({edges[i][0],i});
        }
        for(int i=0;i<n;i++)
        {
            if(s[i]+d[i]!=t)
                for(auto e : g[i]) r[e.second]=false;
        }
        for(int i=0;i<edges.size();i++)
        {
            if(abs(s[edges[i][0]]-s[edges[i][1]])!=edges[i][2]) r[i]=false;
        }
        return r;            
    }
};