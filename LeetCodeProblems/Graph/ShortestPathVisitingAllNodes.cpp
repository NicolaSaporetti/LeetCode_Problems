#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& adjList) {
        queue<pair<int, int>> q;
		
        int n = adjList.size();
        for(int i=0; i<n; i++){
            int maskWithIVisited = setBit(0, i);
            q.push({i, maskWithIVisited});
        }
		
        int allVisitedMask = pow(2, n) -1;
        
        vector<vector<bool>> visited;
        int row = pow(2,n);
        int col = n; 
        visited.resize(row, vector<bool>(col, false));

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
					
                    if(!visited[neighborVisitedMask][neighbor]){
                        visited[neighborVisitedMask][neighbor] = true;
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
        return mask | (1 << bit);
    }
};