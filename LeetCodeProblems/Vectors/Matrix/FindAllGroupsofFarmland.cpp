#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        rz = land.size();
        cz = land[0].size();
        for(int i=0;i<rz;i++)
        {
            for(int j=0;j<cz;j++)
            {
                if(land[i][j]==1) composeFarm(i,j,land);
            }
        }
        return result;
    }
private:
    void composeFarm(int r, int c, vector<vector<int>>& land)
    {
        int rd = 1;
        int cd = 1;
        while(c+cd<cz && land[r][c+cd]==1) cd++;
        while(r+rd<rz && land[r+rd][c]==1) rd++;
        for(int i=r;i<r+rd;i++)
        {
            for(int j=c;j<c+cd;j++) land[i][j]=0;
        }
        result.push_back({r,c,r+rd-1,c+cd-1});
    }
    
    vector<vector<int>> result;
    int rz;
    int cz;
};