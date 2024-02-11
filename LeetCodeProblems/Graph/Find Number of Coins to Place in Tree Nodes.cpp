#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<long long> placedCoins(vector<vector<int>>& edges, vector<int>& cost) {
        sz = cost.size();
        nodes.resize(sz);
        vector<vector<int>> gtl = buildDirectGraphToLeafs(edges, sz);
        vector<int> gtr = buildDirectGraphToRoot(gtl,sz);
        vector<int> adj(sz,0);
        queue<int> q;
        for(int i=0;i<sz;i++)
        {
            adj[i]=gtl[i].size();
            if(gtl[i].size()==0) q.push(i);
        }
        vector<long long> res(sz,0);
        while(!q.empty())
        {
            auto el = q.front();
            q.pop();
            nodes[el].push_back(cost[el]);
            sort(begin(nodes[el]),end(nodes[el]));
            int Tel = gtr[el];
            int nodesSz = nodes[el].size();
            if(Tel!=-1)
            {
                adj[Tel]--;
                if(adj[Tel]==0) q.push(Tel);
                for(int i=0;i<min(nodesSz,2);i++) nodes[Tel].push_back(nodes[el][i]);
                for(int i=0;i<min(nodesSz-2,3);i++) nodes[Tel].push_back(nodes[el][nodesSz-1-i]);
            }
            if(nodes[el].size()<3) res[el]=1;
            else
            {
                long long v1 = 0;
                long long v2 = 0;
                long long v3 = nodes[el].back();
                if(nodes[el][0]<0 && nodes[el][1]<0) v1 = nodes[el][0]*nodes[el][1];
                if(nodes[el][nodesSz-2]>0 && nodes[el][nodesSz-3]>0) v2 = nodes[el][nodesSz-2] * nodes[el][nodesSz-3];
                long long r = v3*max(v1,v2);
                if(v3<=0) res[el]=0;
                else res[el]=r;
            }
        }
        return res;
    }

    vector<vector<int>> buildDirectGraphToLeafs(vector<vector<int>>& edges, int sz)
    {
        vector<set<int>> m(sz);
        vector<vector<int>> res(sz);
        for(auto e : edges)
        {
            m[e[0]].insert(e[1]);
            m[e[1]].insert(e[0]);
        }
        queue<int> q;
        q.push(0);
        while(!q.empty())
        {
            int el = q.front();
            q.pop();
            for(auto e : m[el])
            {
                m[e].erase(el);
                q.push(e);
            }
        }
        for(int i=0;i<sz;i++)
            for(auto e : m[i]) res[i].push_back(e);
        return res;
    }

    vector<int> buildDirectGraphToRoot(vector<vector<int>>& graphRootToLeaf, int sz)
    {
        vector<int> res(sz,-1);
        for(int i=0;i<sz;i++)
            for(int j=0;j<graphRootToLeaf[i].size();j++) res[graphRootToLeaf[i][j]]=i;
        return res;
    }
    int sz;
    vector<vector<int>> nodes;
};