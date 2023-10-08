#include <queue>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        int start = setup(n,edges);
        compute(start);
        return res;
    }
    
private:
    int setup(int n, vector<vector<int>>& edges)
    {
        out.resize(n);
        this->n=n;
        in.resize(n);
        con.assign(n,0);
        outg.assign(n,0);
        vis.assign(n,false);
        res.assign(n,0);
        for(auto& e : edges)
        {
            out[e[0]].push_back(e[1]);
            in[e[1]].push_back(e[0]);
            con[e[0]]++;
            con[e[1]]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++) if(con[i]==1) q.push(i);
        int fin = q.front();
        q.pop();
        while(!q.empty())
        {
            int el = q.front();
            vis[el]=true;
            q.pop();
            for(auto e : in[el])
            {
                if(vis[e]) continue;
                con[e]--;
                outg[e]+=(1+outg[el]);
                if(con[e]==1) q.push(e);
            }
            for(auto e : out[el])
            {
                if(vis[e]) continue;
                con[e]--;
                outg[e]+=outg[el];
                if(con[e]==1) q.push(e);
            }
        }
        vis.assign(n,false);
        res[fin]=n-1-outg[fin];
        return fin;
    }

    void compute(int el)
    {
        vis[el]=true;
        for(auto e : in[el])
        {
            if(vis[e]) continue;
            outg[e]=outg[el]+1;
            res[e]=n-1-outg[e];
            compute(e);
        }
        for(auto e : out[el])
        {
            if(vis[e]) continue;
            outg[e]=outg[el]-1;
            res[e]=n-1-outg[e];
            compute(e);
        }
        
    }
    
    vector<vector<int>> out;
    vector<vector<int>> in;
    vector<int> con;
    vector<int> outg;
    vector<int> res;
    vector<bool> vis;
    int n;
};