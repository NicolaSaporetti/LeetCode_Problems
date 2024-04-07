#include <vector>
using namespace std;

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> fill(query_row+1,vector<double>(query_row+1,0));
        fill[0][0]=poured;
        for(int i=0;i<query_row;i++)
        {
            for(int j=0;j<=i;j++)
                if(fill[i][j]>1.0)
                {
                    fill[i+1][j]+=(fill[i][j]-1)/2;
                    fill[i+1][j+1]+=(fill[i][j]-1)/2;
                }
        }
        return min(fill[query_row][query_glass],1.0);
    }
};