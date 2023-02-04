#include <vector>
using namespace std;

class Solution {
public:
    bool isPossibleToCutPath(vector<vector<int>>& grid) {
        rz = grid.size();
        cz = grid[0].size();
        for(int i = 0; i < rz; i++){
            check = count_if(begin(grid[i]),end(grid[i]),[](int el){return el;});
            if(check <= 1) return 1;
        }
        return diagonalOrder(grid);
    }
private:
    bool diagonalOrder(vector<vector<int>>& matrix)
    {
        for(int i=0;i<rz-1;i++){
            check = 0;
            for(int j=0;i+j<rz && j<cz;j++) if(matrix[rz-1-j-i][j]==1) check++;
            if(check<=1) return 1;
        }
        for(int i=1;i<cz-1;i++){
            check = 0;
            for(int j=0;j<rz && i+j<cz;j++) if(matrix[rz-1-j][i+j]==1) check++;
            if(check<=1) return 1;
        }
        return matrix[rz-1][cz-1] == 0;
    }

int rz, cz;
int check;
};