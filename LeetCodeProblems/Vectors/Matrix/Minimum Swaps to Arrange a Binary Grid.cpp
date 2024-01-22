#include <vector>
using namespace std;

class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int rz = grid.size();
        int cz = grid[0].size();
        vector<int> v(rz,0);
        int res = 0;
        for(int i=0;i<rz;i++)
        {
            int r = 0;
            for(int j=cz-1;j>=0;j--)
            {
                if(grid[i][j]!=0) break;
                else r++;
            }
            v[i]=r;
        }
        for(int i=0;i<rz;i++)
        {
            int j=i;
            bool found = false;
            for(;j<rz && !found;j++)
            {
                if(v[j]>=rz-1-i)
                {
                    found = true;
                    break;
                }
            }
            if(!found) return -1;
            res+=(j-i);
            for(int k=0;k<j-i;k++) swap(v[j-k],v[j-k-1]);
        }
        return res;
    }
};