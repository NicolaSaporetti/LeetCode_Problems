#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    int rows;
    int cols;
    vector<vector<bool>> visited;
    
    bool solve(vector<vector<char>>& board, string& word, int currentLetter, int row, int col)
    {
        bool result = false;
        if(board[row][col]==word[currentLetter])
        {
            visited[row][col] = true;
            if(word.size()-1>currentLetter)
            {
                if(row-1>=0 && !result && !visited[row-1][col]) result|= solve(board, word, currentLetter+1, row-1, col);
                if(row+1<rows && !result && !visited[row+1][col]) result|= solve(board, word, currentLetter+1, row+1, col);
                if(col-1>=0 && !result && !visited[row][col-1]) result|= solve(board, word, currentLetter+1, row, col-1);
                if(col+1<cols && !result && !visited[row][col+1]) result|= solve(board, word, currentLetter+1, row, col+1);
            }
            else result = true;
            visited[row][col] = false;
        }
        return result;
    }
    
    void resetVisitedMatrix()
    {
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                visited[i][j]=false;
            }
        }
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        rows = board.size();
        cols = board[0].size();
        visited.resize(rows);
        for(int i=0;i<rows;i++)
        {
            visited[i].resize(cols);
        }
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                resetVisitedMatrix();
                if(solve(board, word, 0, i, j)) return true;
            }
        }
        return false;
    }
};