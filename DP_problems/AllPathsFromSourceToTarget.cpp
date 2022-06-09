#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<vector<int>> solutions;
    vector<int> path;
    
    void computePaths(int node, vector<vector<int>>& graph)
    {
        path.push_back(node);
        if(node !=graph.size()-1)
        {
            for(int j=0;j<graph[node].size();j++)
            {
                computePaths(graph[node][j],graph);
            }
        }
        else
        {
            solutions.push_back(path); 
        }
        path.pop_back();
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        computePaths(0, graph);
        return solutions; 
    }
};