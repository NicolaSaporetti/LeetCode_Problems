#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<set<int>> inEdges(n);
        vector<set<int>> outEdges(n);
        vector<bool> visited(n,false);
        queue<int> myQ;
        int res = 0;
        for(int i=0;i<connections.size();i++)
        {
            int outNode = connections[i][0];
            int inNode = connections[i][1];
            inEdges[inNode].insert(outNode);
            outEdges[outNode].insert(inNode);
        }
        myQ.push(0);
        while(!myQ.empty())
        {
            int elem = myQ.front();
            myQ.pop();
            for(auto it=outEdges[elem].begin();it!=outEdges[elem].end();it++)
            {
                if(!visited[*it])
                {
                    myQ.push(*it);
                    res++;
                }
            }
            for(auto it=inEdges[elem].begin();it!=inEdges[elem].end();it++)
            {
                if(!visited[*it]) myQ.push(*it);
            }
            visited[elem]=true;
        }
        return res;
    }
};