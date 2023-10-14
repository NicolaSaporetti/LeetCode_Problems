#include <vector>
using namespace std;

class Solution {
public:
    int minimumMoves(vector<vector<int>>& grid) {
        return solve(grid);
    }
private:
    int solve(vector<vector<int>>& grid){
        bool ans = true;
        for(int i = 0; i< 3; i++){
            for(int j = 0; j < 3; j++){
                if(grid[i][j] != 1){
                    ans = false;
                    break;
                }
            }
        }
        
        if(ans) return 0;
        
        int count = 1e9;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                for(int k = 0; k < 3; k++){
                    for(int l = 0; l < 3; l++){
                        if(grid[i][j] == 0 && grid[k][l] > 1){
                            grid[k][l] -= 1;
                            grid[i][j] += 1;
                            int d = abs(i - k) + abs(j - l);
                            count = min(count, d + solve(grid));
                            grid[k][l] += 1;
                            grid[i][j] -= 1;
                        }
                    }
                }
            }
        }
        
        return count;
    }
};