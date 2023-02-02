#include <vector>
#include <queue>
#include <set>
using namespace std;

class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> graph(n);
        int t = 0;
        queue<int> q;
        vector<int> vis(n,0);
        for(auto& e : edges)
        {
            graph[e[0]-1].push_back(e[1]-1);
            graph[e[1]-1].push_back(e[0]-1);
        }
        q.push(0);
        vis[0]=1;
        while(!q.empty())
        {
            int num = q.size();
            set<int> s;
            t+=time;
            for(int i=0;i<num;i++)
            {
                int node = q.front();
                q.pop();
                for(int j = 0;j<graph[node].size();j++)
                {
                    int newN = graph[node][j];
                    if(s.find(newN)==s.end() && vis[newN]<2)
                    {
                        vis[newN]++;
                        s.insert(newN);
                        q.push(newN);
                        if(newN==n-1 && vis[newN]==2) return t;
                    }
                }
            }
            int div = t/change;
            if(div%2==1) t =(div+1)*change;
        }
        return -1;
    }
};