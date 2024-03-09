#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        vector<vector<int>> graph = fillGraph(vals, edges);
        map<int, vector<int>> m1;
        for (int i = 0; i < n; ++i) m1[vals[i]].push_back(i);        
        DisjoinSetUnion d(n);
        int ans = n;

        for (auto element : m1) 
        {
            int value = element.first;
            
            for (auto node : element.second) 
            {
                for (auto adjcentNode : graph[node]) 
                {
                    d.connect(node, adjcentNode);
                }
            }
            unordered_map<int, int> nodesWithSameRoot;
            for (auto node : element.second) nodesWithSameRoot[d.find_set(node)]++;
            
            for (auto& base_roots : nodesWithSameRoot) ans+=((base_roots.second*(base_roots.second-1))/2);
        }
        return ans;
    }
private:
    vector<vector<int>> fillGraph(vector<int>& vals, vector<vector<int>>& edges)
    {
        vector<vector<int>> graph(vals.size());
        for (auto& e : edges) 
        {
            int a = e[0];
            int b = e[1];
         
            if (vals[a] >= vals[b]) {
                graph[a].push_back(b);
            }
            if (vals[a] <= vals[b]) {
                graph[b].push_back(a);
            }
        }
        return graph;
    }
};