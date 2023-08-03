#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
        int sz = nums.size();
        graph.resize(sz);
        vis.assign(sz,false);
        res.assign(sz,-1);
        for(auto& e : edges)
        {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        map<int,pair<int,int>> m;
        traverse(0,0,m,nums);
        return res;
    }
private:
    void traverse(int node, int dist, map<int,pair<int,int>> m, vector<int>& nums)
    {
        vis[node]=true;
        int d = -1;
        for(auto& [k,v] : m)
        {
            if(__gcd(k,nums[node])==1 && v.second>d)
            {
                d = v.second;
                res[node]= v.first;
            }
        }
        m[nums[node]]={node,dist};
        for(auto& e : graph[node]) if(!vis[e]) traverse(e, dist+1,m,nums);
    }
    
    vector<int> res;
    vector<bool> vis;
    vector<vector<int>> graph;
};