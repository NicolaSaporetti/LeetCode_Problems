#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        int rz = grid.size();
        int cz = grid[0].size();
        vector<int> res(cz,0);
        for(int i=0;i<cz;i++)
        {
            for(int j=0;j<rz;j++)
            {
                res[i]=max(res[i],computeS(grid[j][i]));
            }
        }
        return res;
    }
    
    int computeS(int num)
    {
        int dim = 0;
        if(num<0)
        {
            dim++;
            num*=-1;
        }
        if(num==0) return 1;
        while(num>0)
        {
            dim++;
            num/=10;
        }
        return dim;
    }
};