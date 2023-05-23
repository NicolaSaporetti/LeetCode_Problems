#include <vector>
#include "DisjoinSet.cpp"
using namespace std;

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int cableAvailable = 0;
        DisjoinSet dset(n);
        for(int i=0;i<connections.size();i++)
        {
            if(dset.are_connect(connections[i][0],connections[i][1])) cableAvailable++;
            else dset.connect(connections[i][0],connections[i][1]);
        }
        int numberOfSets=dset.get_sets();
        if(cableAvailable>=numberOfSets-1) return numberOfSets-1;
        else return -1;
    }
};