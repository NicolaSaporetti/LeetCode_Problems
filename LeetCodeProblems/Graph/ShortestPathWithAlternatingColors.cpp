#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<bool> visitedR(n,false);
        vector<bool> visitedB(n,false);
        vector<set<int>> outEdgesR(n);
        vector<set<int>> outEdgesB(n);
        res.resize(n);
        for(int i=0;i<n;i++) res[i]=INT_MAX;
        q_red.push(0);
        q_blue.push(0);
        
        initOutEdges(redEdges,outEdgesR);
        initOutEdges(blueEdges,outEdgesB);
		computeshortestPathBinaryMatrix(outEdgesR,outEdgesB,visitedR,visitedB);
        for(int i=0;i<n;i++) if(res[i]==INT_MAX) res[i]=-1;
        return res;
    }
        
private:
    
    void initOutEdges(vector<vector<int>>& connections, vector<set<int>>& outEdges)
    {
        for(int i=0;i<connections.size();i++) outEdges[connections[i][0]].insert(connections[i][1]);
    }
    
    void computeshortestPathBinaryMatrix(vector<set<int>> outEdgesR, vector<set<int>> outEdgesB, vector<bool> visitedR, vector<bool> visitedB) {
        int distance = 0;
        while(!q_red.empty() || !q_blue.empty())
        {
            int Nred = q_red.size();
            int Nblue = q_blue.size();
            queue<int> tempR;
            for(int i=0;i<Nred;i++)
            {
                int redN = q_red.front();
                visitedR[redN] = true;
                res[redN] = min(res[redN],distance);
                q_red.pop();
                
                for(auto it =outEdgesB[redN].begin();it!=outEdgesB[redN].end();it++)
                {
                    if(!visitedB[*it])
                    {
                        q_blue.push(*it);
                    }
                }
            }
            for(int i=0;i<Nblue;i++)
            {
                int blueN = q_blue.front();
                visitedB[blueN] = true;
                res[blueN] = min(res[blueN],distance);
                q_blue.pop();
                for(auto it =outEdgesR[blueN].begin();it!=outEdgesR[blueN].end();it++)
                {
                    if(!visitedR[*it])
                    {
                        q_red.push(*it);
                    }
                }
            }
            distance++;
        }
    }
    
    vector<int> res;
    queue<int> q_red;
    queue<int> q_blue;
};