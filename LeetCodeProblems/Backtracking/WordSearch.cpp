#include <vector>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        rz = board.size();
        cz = board[0].size();
        x = {0,0,1,-1};
        y = {1,-1,0,0};
        visited.assign(rz,vector<bool>(cz,false));
        this->word = std::move(word);
        for(int i=0;i<rz;i++)
            for(int j=0;j<cz;j++) 
                if(solve(board, 0, i, j)) return true;
        return false;
    }
    
private:
    bool solve(vector<vector<char>>& board, int currentLetter, int row, int col)
    {
        if(board[row][col]==word[currentLetter])
        {
            visited[row][col] = true;
            if(word.size()-1==currentLetter) return true;
            else
            {
                bool result = false;
                for(int i=0;i<4 && !result;i++)
                {
                    int dx = row+x[i];
                    int dy = col+y[i];
                    if(dx<0 || dx>=rz || dy<0 || dy>=cz || visited[dx][dy]) continue;
                    result = solve(board,currentLetter+1,dx,dy);
                }
                visited[row][col] = false;
                return result;
            }
        }
        else return false;
    }
    
    int rz;
    int cz;
    string word;
    vector<vector<bool>> visited;
    vector<int> x = {0,0,1,-1};
    vector<int> y = {1,-1,0,0};
};