#include "TreeNode.cpp"
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> smallestMissingValueSubtree(vector<int>& parents, vector<int>& nums) {
        setup(parents);
        int node = min_element(begin(nums),end(nums))-nums.begin();
        do
        {
            addVisited(node,nums);
            result[node]=val;
            node = parents[node];
        }
        while(node!=-1);
        return result;
    }
private:
    void setup(vector<int>& parents)
    {
        sz = nums.size();
        result.assign(sz,1);
        visited.assign(sz,false);
        graph.resize(sz);
        val = 1;
        for(int i=1;i<sz;i++) graph[parents[i]].push_back(i);
    }

    void addVisited(int node, vector<int>& nums)
    {
        visited[node]=true;
        s.insert(nums[node]);
        while(s.count(val)) val++;
        for(int i=0;i<graph[node].size();i++)
        {
            if(!visited[graph[node][i]]) addVisited(graph[node][i],nums);
        }
    }
    
    vector<vector<int>> graph;
    set<int> s;
    vector<bool> visited;
    vector<int> result;
    int val;
    int sz;
};