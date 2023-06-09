#include <map>
using namespace std;

class Solution {
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        int rz = grid.size();
        int cz = grid[0].size();
        vector<vector<int>> res(rz,vector<int>(cz,0));
        int j=0;
        for(int i=0;i<rz;i++)
        {
            map<int,int> tl;
            map<int,int> br;
            for(int j=0;i+j<rz && j<cz;j++)
            {
                br[grid[i+j][j]]++;
            }
            for(int j=0;i+j<rz && j<cz;j++)
            {
                br[grid[i+j][j]]--;
                if(br[grid[i+j][j]]==0) br.erase(grid[i+j][j]);
                res[i+j][j]=abs((int)tl.size()-(int)br.size());
                tl[grid[i+j][j]]++;
            }
        }
        for(int j=1;j<cz;j++)
        {
            map<int,int> tl;
            map<int,int> br;
            for(int i=0;i+j<cz && i<rz;i++)
            {
                br[grid[i][j+i]]++;
            }
            for(int i=0;i+j<cz && i<rz;i++)
            {
                br[grid[i][j+i]]--;
                if(br[grid[i][j+i]]==0) br.erase(grid[i][j+i]);
                res[i][j+i]=abs((int)tl.size()-(int)br.size());
                tl[grid[i][j+i]]++;
            }
        }
        return res;
    }
};