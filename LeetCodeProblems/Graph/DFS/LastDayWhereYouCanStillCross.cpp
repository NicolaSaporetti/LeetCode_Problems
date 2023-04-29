#include <vector>
#include <queue>
#include <array>
using namespace std;

class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int minDay = 0;
        int maxDay = row*(col-1);
        int res = minDay;
        while(minDay<=maxDay)
        {
            int avg = (maxDay+minDay)/2;
            if(canTraverse(row,col,cells,avg))
            {
                res = avg;
                minDay = avg+1;
            }
            else maxDay = avg-1;
        }
        return res;
    }
private:
    bool canTraverse(int row, int col, vector<vector<int>>& cells, int n)
    {
        vector<vector<bool>> m(row,vector<bool>(col,true));
        for(int i=0;i<n;i++) m[cells[i][0]-1][cells[i][1]-1]=false;
        queue<pair<int,int>> q;
        for(int i=0;i<col;i++) if(m[0][i]) q.push({0,i});
        array<int,4> row_pos = {1,-1,0,0};
        array<int,4> col_pos = {0,0,1,-1};
        do {
            int num = q.size();
            for(int i=0;i<num;i++)
            {
                auto el = q.front();
                if(el.first==row-1) return true;
                q.pop();
                for(int j=0;j<4;j++)
                {
                    int nr = el.first+row_pos[j];
                    int nc = el.second+col_pos[j];
                    if(nr>=0 && nr<row && nc>=0 && nc<col && m[nr][nc])
                    {
                        m[nr][nc]=false;
                        q.push({nr,nc});
                    }
                }
            }
        } while(!q.empty());
        return false;
    }
};