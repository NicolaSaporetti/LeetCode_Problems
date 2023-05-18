#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> res;
        vector<int> incomingEdges(n,0);
        for(auto& e : edges) incomingEdges[e[1]]++;
        for(int i=0;i<n;i++) if(incomingEdges[i]==0) res.push_back(i);
        return res;
    }
};