#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    long long countPalindromePaths(vector<int>& parent, string s) {
        vector<vector<int>> graph;
        int sz= parents.size();
        for(int i=0;i<sz;i++) if(parents[i]!=-1) graph[parents[i]].push_back(i);
        traverse(graph,s,0,0,-1);
    }
    
    void traverse(vector<vector<int>>& graph, string& s, int node, int mask, int prev)
    {
        mask&=~(1<<(s[node]-'a'));
        map[mask]++;
        for(auto& e : graph[node])
        {
            mask
            traverse(graph,e);
        }
        map[mask]--;
    }
    
    map<int,int> m;
};