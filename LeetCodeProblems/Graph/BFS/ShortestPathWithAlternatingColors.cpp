#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        visitedB.assign(n,false);
        visitedR.assign(n,false);
        graphBR.resize(n);
        graphRB.resize(n);
        res.assign(n,INT_MAX);
        for(auto& e : redEdges) graphRB[e[0]].push_back(e[1]);
        for(auto& e : blueEdges) graphBR[e[0]].push_back(e[1]);
        qB.push(0);
        qR.push(0);
        visitedB[0]=true;
        visitedR[0]=true;
        computeshortestPath();
        transform(begin(res),end(res),begin(res),[&](int elem){return (elem==INT_MAX)?-1:elem;});
        return res;
    }
        
private:    
    void computeshortestPath() {
        int distance = 0;
        while(!qR.empty() || !qB.empty())
        {
            int Nred = qR.size();
            int Nblue = qB.size();
            for(int i=0;i<Nred;i++)
            {
                int redN = qR.front();
                qR.pop();
                res[redN] = min(res[redN],distance);
                
                for(int j=0;j<graphRB[redN].size();j++)
                {
                    int nodeB = graphRB[redN][j];
                    if(!visitedB[nodeB])
                    {
                        qB.push(nodeB);
                        visitedB[nodeB]=true;
                    }
                }
            }
            for(int i=0;i<Nblue;i++)
            {
                int blueN = qB.front();
                qB.pop();
                res[blueN] = min(res[blueN],distance);
                
                for(int j=0;j<graphBR[blueN].size();j++)
                {
                    int nodeR = graphBR[blueN][j];
                    if(!visitedR[nodeR])
                    {
                        qR.push(nodeR);
                        visitedR[nodeR]=true;
                    }
                }
            }
            distance++;
        }
    }
    
    vector<int> res;
    vector<bool> visitedB;
    vector<bool> visitedR;
    vector<vector<int>> graphRB;
    vector<vector<int>> graphBR;
    queue<int> qB;
    queue<int> qR;
};