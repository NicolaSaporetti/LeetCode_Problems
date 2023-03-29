#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
        sz = coins.size();
        int res = 0;
        for(auto& e : edges)
        {
            graph[e[0]].insert(e[1]);
            graph[e[1]].insert(e[0]);
        }
        simplify_graph_without_coin(coins);
        simplify_graph();
        return max(0,int(graph.size()-1)*2);
    }
private:
    void simplify_graph_without_coin(vector<int>& coins)
    {
        queue<int> leaf;
        for(int i=0;i<sz;i++)
        {
            if(graph[i].size()==1 && !coins[i]) leaf.push(i);
        }
        while(!leaf.empty())
        {
            int n = leaf.size();
            for(int i=0;i<n;i++)
            {
                int el = leaf.front();
                leaf.pop();
                for(auto& e : graph[el])
                {
                    graph[e].erase(el);
                    if(graph[e].size()==1 && !coins[e]) leaf.push(e);
                }
                graph.erase(el);
            }
        }
    }
    void simplify_graph()
    {
        vector<int> leaf;
        vector<int> dist_1;
        for(auto& [key,connections] : graph)
        {
            if(connections.size()==1) leaf.push_back(key);
        }
        for(auto& l : leaf)
        {
            for(auto& e : graph[l])
            {
                graph[e].erase(l);
                if(graph[e].size()==1) dist_1.push_back(e);
            }
            graph.erase(l);
        }
        for(auto& l : dist_1)
        {
            for(auto& e : graph[l])
            {
                graph[e].erase(l);
            }
            graph.erase(l);
        }
    }
    
    unordered_map<int,unordered_set<int>> graph;
    int sz;
};