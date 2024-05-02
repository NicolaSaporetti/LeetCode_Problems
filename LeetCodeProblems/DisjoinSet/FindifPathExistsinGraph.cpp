#include <vector>
#include "DisjoinSetUnion.cpp"
using namespace std;

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        DisjoinSetUnion ds(n);
        for(auto e : edges) ds.connect(e[0],e[1]);
        return ds.are_connect(source,destination);
    }
};