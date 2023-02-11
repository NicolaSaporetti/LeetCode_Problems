#include <vector>
using namespace std;

class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int cz = grid[0].size();
        vector<vector<long long>> v(2,vector<long long>(cz,0));
        for(int i=0;i<cz-1;i++)
        {
            v[0][i+1]=v[0][i]+(long long)(grid[0][cz-1-i]);
            v[1][i+1]=v[1][i]+(long long)(grid[1][i]);
        }
        int p1 = cz-1;
        int p2 = cz-1;
        for(int i=0;i<cz-1;i++)
        {
            if(p2==-1 || ((p1>=0) && v[0][p1]>=v[1][p2])) p1--;
            else p2--;
        }
        return max(v[0][p1], v[1][p2]);
    }
};