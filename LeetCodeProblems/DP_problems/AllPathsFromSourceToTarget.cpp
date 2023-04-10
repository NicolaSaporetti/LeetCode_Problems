#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        computePaths(0, graph);
        return solutions; 
    }
private:    
    void computePaths(int node, vector<vector<int>>& graph)
    {
        path.push_back(node);
        if(node ==graph.size()-1) solutions.push_back(path); 
        else 
        {
            for(int j=0;j<graph[node].size();j++) computePaths(graph[node][j],graph);
        }
        path.pop_back();
    }

    vector<vector<int>> solutions;
    vector<int> path;
};