#include <iostream>
#include <vector>
#include "DisjoinSet.cpp"
using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int sz = isConnected.size();
        DisjoinSet set(sz);
        for(int i = 0; i < sz; i++)
        {
            for(int j = i+1; j < sz; j++)
                if(isConnected[i][j])
                {
                    set.connect(i,j);
                }
        }
        return set.get_sets();
    }
};