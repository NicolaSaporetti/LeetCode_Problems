#include <vector>
using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<int> dx={-1,-1,-1,0,1,1,1,0};
        vector<int> dy={-1,0,1,1,1,0,-1,-1};
        int rz = board.size();
        int cz = board[0].size();
        vector<vector<int>> r(rz,vector<int>(cz,0));
        for(int i=0;i<rz;i++)
        {
            for(int j=0;j<cz;j++)
            {
                int nei = 0;
                for(int z=0;z<8;z++)
                {
                    int nx = i+dx[z];
                    int ny = j+dy[z];
                    if(nx<0 || nx>=rz || ny<0 || ny>=cz) continue;
                    if(board[nx][ny]) nei++;
                }
                if(board[i][j]==1 && nei>=2 && nei<=3) r[i][j]=1;
                if(board[i][j]==0 && nei==3) r[i][j]=1;
            }
        }
        board = r;
    }
};