#include <vector>
#include "ValidSudoku.cpp"
using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        sz = board.size();
        complete_board(board,0,0);
    }
    
private:
    bool complete_board(vector<vector<char>>& board, int row, int column)
    {
        if(sudoku.isValidSudoku(board,row,column))
        {
            while(row<sz && board[row][column]!='.')
            {
                column++;
                if(column==sz)
                {
                    row++;
                    column=0;
                }
            }
            if(row==sz) return true;
            else
            {
                bool isValid = false;
                set<char> s;
                for(int i=0;i<sz;i++) s.insert('1'+i);
                for(int i=0;i<sz;i++) if(board[row][i]!='.') s.erase(board[row][i]);
                for(int i=0;i<sz;i++) if(board[i][column]!='.') s.erase(board[i][column]);
                for(int i=(row/3)*3;i<(row/3)*3+3;i++)
                    for(int j=(column/3)*3;j<(column/3)*3+3;j++) if(board[i][j]!='.') s.erase(board[i][j]);
                for(auto it=s.begin();it!=s.end() && !isValid;it++)
                {
                    board[row][column]=*it;
                    isValid=complete_board(board,row,column);
                }
                if(!isValid) board[row][column]='.';
                return isValid;
            }
        }
        else return false;
    }
    
    ValidSudoku sudoku;
    int sz;
};