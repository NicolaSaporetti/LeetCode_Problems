#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        int rz = grid.size();
        int cz = grid[0].size();
        vector<vector<int>> r(rz,vector<int>(cz,0));
        for(int i=0;i<rz;i++)
        {
            map<int,int> m;
            map<int,int> m2;
            for(int j=0;j+i<rz && j<cz;j++) m[grid[i+j][j]]++;
            for(int j=0;j+i<rz && j<cz;j++)
            {
                m[grid[i+j][j]]--;
                if(m[grid[i+j][j]]==0) m.erase(grid[i+j][j]);
                r[i+j][j]=abs((int)m.size()-(int)m2.size());
                m2[grid[i+j][j]]++;
            }
        }
        for(int j=1;j<cz;j++)
        {
            map<int,int> m;
            map<int,int> m2;
            for(int i=0;i<rz && j+i<cz;i++) m[grid[i][i+j]]++;
            for(int i=0;i<rz && j+i<cz;i++)
            {
                m[grid[i][i+j]]--;
                if(m[grid[i][i+j]]==0) m.erase(grid[i][i+j]);
                r[i][i+j]=abs((int)m.size()-(int)m2.size());
                m2[grid[i][i+j]]++;
            }
        }
        return r;
    }
};