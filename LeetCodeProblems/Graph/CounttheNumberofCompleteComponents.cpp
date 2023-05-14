#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        v.resize(n);
        vis.assign(n,false);
        int tot = 0;
        for(auto& e : edges)
        {
            v[e[0]].push_back(e[1]);
            v[e[1]].push_back(e[0]);
        }
        for(int i=0;i<n;i++)
        {
            if(vis[i]==false)
            {
                tot+=isComplete(i);
            }
        }
        return tot;
    }
private:
    bool isComplete(int start)
    {
        int edges = 0;
        int nodes = 0;
        queue<int> q;
        q.push(start);
        vis[start]=true;
        while(!q.empty())
        {
            int el = q.front();
            q.pop();
            nodes++;
            edges+=v[el].size();
            for(int i=0;i<v[el].size();i++)
            {
                int new_el = v[el][i];
                if(vis[new_el]==false)
                {
                    vis[new_el]=true;
                    q.push(new_el);
                }
            }
        }
        return (edges==nodes*(nodes-1));
    }
    
    vector<vector<int>> v;
    vector<int> vis;
};