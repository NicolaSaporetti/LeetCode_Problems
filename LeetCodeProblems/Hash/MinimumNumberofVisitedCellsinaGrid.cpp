#include <vector>
#include <map>
#include <set>
using namespace std;

class Solution {
public:
    int minimumVisitedCells(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        setup(grid);
        int res = 1;
        q.push({0,0});
        row[0].erase(0);
        col[0].erase(0);
        while(!q.empty())
        {
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                int r=q.front().first;
                int c=q.front().second;
                q.pop();
                if(r ==rz-1 && c == cz-1) return res;
                auto it = row[r].lower_bound(c);
                while(it!=row[r].end() && *it<=c+grid[r][c])
                {
                    q.push({r,*it});
                    col[*it].erase(r);
                    row[r].erase(it++);
                }
                it = col[c].lower_bound(r);
                while(it!=col[c].end() && *it<=r+grid[r][c])
                {
                    q.push({*it,c});
                    row[*it].erase(c);
                    col[c].erase(it++);
                }
            }
            res++;
        }
        return -1;
    }
private:
    void setup(vector<vector<int>>& grid)
    {
        rz = grid.size();
        cz = grid[0].size();
        for(int i=0;i<rz;i++)
        {
            for(int j=0;j<cz;j++)
            {
                row[i].insert(j);
                col[j].insert(i);
            }
        }
    }
    
    int rz;
    int cz;
    map<int,set<int>> col;
    map<int,set<int>> row;
};