#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& adjList) {
        this->n = adjList.size();
        queue<pair<int, int>> q;
		
        fillQueue(adjList);
		
        int allVisitedMask = pow(2, n) -1;
        vector<vector<int>> visited(pow(2,n), vector<int>(n, 0));
        
        //Perform BFS
		
        int level = 0;
        while(!q.empty()){
            int qSize = q.size();
            
            for(int i=0; i<qSize; i++){
                auto nodeMask = q.front();
                q.pop();
                int node = nodeMask.first, mask = nodeMask.second;
                if(mask == allVisitedMask) return level;

                for(auto neighbor: adjList[node]){
                    int neighborVisitedMask = setBit(mask, neighbor);
					
                    if(visited[neighborVisitedMask][neighbor] == 0)
                    {
                        visited[neighborVisitedMask][neighbor] = 1;
                        q.push({neighbor, neighborVisitedMask});
                    }
                }
            }
            level += 1;
        }
        return -1;
    }
    
private:
    int setBit(int mask, int bit){
        int res = mask | (1 << bit);
        return res;
    }

    void fillQueue(vector<vector<int>>& adjList)
    {
        int n = adjList.size();
        for(int i=0; i<n; i++){
            int maskWithIVisited = setBit(0, i);
            q.push({i, maskWithIVisited});
        }
    }

    int n;
};