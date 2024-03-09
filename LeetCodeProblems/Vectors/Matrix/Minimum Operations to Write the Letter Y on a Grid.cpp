#include <vector>
using namespace std;

class Solution {
public:
    int minimumOperationsToWriteY(vector<vector<int>>& grid) {
        vector<int> v(3,0);
        vector<int> y(3,0);
        int sz = grid.size();
        int yDim = sz+sz/2;
        int totDim = sz*sz-yDim;
        for(auto e : grid)
            for(auto c : e) v[c]++;
        for(int i=0;i<sz/2;i++)
        {
            y[grid[i][i]]++;
            y[grid[i][sz-1-i]]++;
            y[grid[sz/2+1+i][sz/2]]++;
        }
        y[grid[sz/2][sz/2]]++;
        for(int i=0;i<3;i++) v[i]-=y[i];
        int r = INT_MAX;
        r = min(r,yDim-y[0]+min(v[0]+v[1],v[0]+v[2]));
        r = min(r,yDim-y[1]+min(v[1]+v[2],v[1]+v[0]));
        r = min(r,yDim-y[2]+min(v[2]+v[1],v[0]+v[2]));
        return r;
    }
};