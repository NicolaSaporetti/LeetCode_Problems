#include <iostream>
#include <vector>
#include "DisjoinSet.cpp"
using namespace std;

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int numberOperationRequested = -1;
        int sz = connections.size();
        cableAvailable = 0;
        DisjoinSet dset(n);
        for(int i=0;i<sz;i++)
        {
            if(dset.are_connect(connections[i][0],connections[i][1])) cableAvailable++;
            else dset.connect(connections[i][0],connections[i][1]);
        }
        int numberOfSets=dset.get_sets();
        if(numberOfSets==1) numberOperationRequested = 0;
        else
        {
            if(cableAvailable>=numberOfSets-1) numberOperationRequested = numberOfSets-1;
        }
        return numberOperationRequested;
    }
private:
    int cableAvailable;
};