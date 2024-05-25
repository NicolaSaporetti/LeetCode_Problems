#include <vector>
using namespace std;

class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        int rz = grid.size();
        int cz = grid[0].size();
        long long r = 0;
        vector<long long> t(rz);
        for(int i=0;i<rz;i++)
        {
            long long v = 0;
            for(int j=0;j<cz;j++) v+=grid[i][j];
            v = max(0LL,v-1);
            t[i]=v;
        }
        for(int i=0;i<cz;i++)
        {
            long long v = 0;
            long long t1 = 0;
            for(int j=0;j<rz;j++)
            {
                v+=grid[j][i];
                if(grid[j][i]) t1+=t[j];
            }
            if(v>=2) r+=(t1*(v-1));
        }
        return r;
    }
};