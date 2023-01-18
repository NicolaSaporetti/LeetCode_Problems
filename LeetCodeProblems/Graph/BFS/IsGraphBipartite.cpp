#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int sz=graph.size();
        vector<int> elementsEvaluated(sz,-1);
        for(int i=0;i<sz;i++)
        {
            if(elementsEvaluated[i]==-1)
            {
                queue<int> q;
                int val = 0;
                q.push(i);
                while(!q.empty())
                {
                    int num = q.size();
                    for(int j=0;j<num;j++)
                    {
                        int el = q.front();
                        q.pop();
                        elementsEvaluated[el]=val;
                        for(int z=0;z<graph[el].size();z++)
                        {
                            int newEl = graph[el][z];
                            if(elementsEvaluated[newEl]==-1) q.push(newEl);
                            else if(elementsEvaluated[newEl]==val) return false;
                        }
                    }
                    val = (val+1)%2;
                }
            }
        }
        return true;
    }
};