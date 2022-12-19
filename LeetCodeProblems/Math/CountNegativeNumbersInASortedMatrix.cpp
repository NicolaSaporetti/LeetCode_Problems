#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int total = 0;
        int col_sz=grid[0].size();
        int row_sz=grid.size();
        int pos=col_sz;
        for(int i=0;i<row_sz;i++)
        {
            while(pos>0 && grid[i][pos-1]<0) pos--;
            total+=(col_sz-pos);
        }
        return total;
    }
};