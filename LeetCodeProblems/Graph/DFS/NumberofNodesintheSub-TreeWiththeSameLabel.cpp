#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> graph = buildDirectGraphToLeafs(edges,n);
        vector<int> result(n,0);
        subtreeElements.assign(n,vector<int>(26,0));
        for(int i=0;i<n;i++) subtreeElements[i][labels[i]-'a']++;
        computeSimilarElements(graph, 0);
        for(int i=0;i<n;i++) result[i]=subtreeElements[i][labels[i]-'a'];
        return result;
    }
private:
    vector<vector<int>> buildDirectGraphToLeafs(vector<vector<int>>& edges, int sz)
    {
        vector<set<int>> m(sz);
        vector<vector<int>> res(sz);
        for(auto e : edges)
        {
            m[e[0]].insert(e[1]);
            m[e[1]].insert(e[0]);
        }
        queue<int> q;
        q.push(0);
        while(!q.empty())
        {
            int el = q.front();
            q.pop();
            for(auto e : m[el])
            {
                m[e].erase(el);
                q.push(e);
            }
        }
        for(int i=0;i<sz;i++)
            for(auto e : m[i]) res[i].push_back(e);
        return res;
    }

    void computeSimilarElements(vector<vector<int>>& graph, int node)
    {
        for(int i=0;i<graph[node].size();i++)
        {
            int newNode = graph[node][i];
            computeSimilarElements(graph, newNode);
            for(int i=0;i<26;i++) subtreeElements[node][i]+=subtreeElements[newNode][i];
        }
    }

    vector<vector<int>> subtreeElements;
};