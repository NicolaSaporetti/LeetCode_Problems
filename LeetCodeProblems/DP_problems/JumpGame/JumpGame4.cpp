#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int sz = arr.size();
        int res = 0;
        map<int,vector<int>> m;
        vector<int> vis(sz,false);
        queue<int> q;
        for(int i=0;i<sz;i++) m[arr[i]].push_back(i);
        q.push(0);
        vis[0]=true;
        while(!q.empty())
        {
            int n = q.size();
            for(int i=0;i<n;i++)
            {
                int node = q.front();
                int nodeVal = arr[node];
                q.pop();
                if(node == sz-1) return res;
                if(node-1>0 && !vis[node-1])
                {
                    q.push(node-1);
                    vis[node-1]=true;
                }
                if(node+1<sz && !vis[node+1])
                {
                    q.push(node+1);
                    vis[node+1]=true;
                }
                for(int j=0;j<m[nodeVal].size();j++)
                {
                    int newNode = m[nodeVal][j];
                    if(!vis[newNode])
                    {
                        q.push(newNode);
                        vis[newNode];
                    }
                }
                m.erase(nodeVal);
            }
            res++;
        }
        return res;
    }
};