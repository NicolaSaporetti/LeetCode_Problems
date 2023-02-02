#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int countHighestScoreNodes(vector<int>& parents) {
        map<long long,int> res;
        int sz = parents.size();
        childs.assign(sz,0);
        vector<vector<int>> graph(sz);
        for(int i=1;i<sz;i++) graph[parents[i]].push_back(i);
        computeChild(graph,0);
        for(int i=0;i<sz;i++)
        {
            if(graph[i].size()==0) res[sz-1]++;
            else if(graph[i].size()==1)
            {
                long long c1 = 1+childs[graph[i][0]];
                res[c1*(long long)(max(1,(int)(sz-c1-1)))]++;
            }
            else
            {
                long long c1 = 1+childs[graph[i][0]];
                long long c2 = 1+childs[graph[i][1]];
                res[c1*c2*(long long)(max(1,(int)(sz-c1-c2-1)))]++;
            }
            
        }
        return res.rbegin()->second;
    }
private:
    int computeChild(vector<vector<int>>& graph, int node)
    {
        for(int i=0;i<graph[node].size();i++) childs[node] += computeChild(graph,graph[node][i]);
        return 1+childs[node];
    }
    
    vector<long long> childs;
};