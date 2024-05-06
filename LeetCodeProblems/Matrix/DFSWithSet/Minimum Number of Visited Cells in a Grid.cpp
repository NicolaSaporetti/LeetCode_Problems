#include <vector>
#include <queue>
#include <set>
using namespace std;

class Solution {
public:
    int minimumVisitedCells(vector<vector<int>>& grid) {
        int rz = grid.size();
        int cz = grid[0].size();
        vector<set<int>> cava(cz);
        vector<set<int>> rava(rz);
        for(int i=0;i<rz;i++)
            for(int j=0;j<cz;j++) rava[i].insert(j);
        for(int i=0;i<cz;i++)
            for(int j=0;j<rz;j++) cava[i].insert(j);
        queue<pair<int,int>> q;
        rava[0].erase(0);
        cava[0].erase(0);
        q.push({0,0});
        int cost = 1;
        while (!q.empty())
        {
            int n = q.size();
            for(int j=0;j<n;j++)
            {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                if(row==rz-1 && col ==cz-1) return cost;
                for (auto it = rava[row].upper_bound(col);it!=rava[row].end() && *it<=col+grid[row][col];rava[row].erase(it++))
                {
                    q.push({row,*it});
                    cava[*it].erase(row);
                }
                for (auto it = cava[col].upper_bound(row);it!=cava[col].end() && *it<=row+grid[row][col];cava[col].erase(it++))
                {
                    q.push({*it,col});
                    rava[*it].erase(col);
                }
            }
            cost++;
        }
        return -1;
    }
};