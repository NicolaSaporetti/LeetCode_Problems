#include <iostream>
#include <stdlib.h>
#include <vector>
#include "Sudoku_checker.cpp"

using namespace std;

class Solution {
private:
    Sudoku_checker sudoku;
    bool complete_board(vector<vector<char>>& board, int row, int column)
    {
        if(sudoku.isValidSudoku(board,row,column))
        {
            if(column==board.size()-1)
            {
                row++;
                column=0;
            }
            else{
                column++;
            }
            for(int i=row;i<board.size();i++)
            {
                for(int j=column;j<board[i].size();j++)
                {
                    if(board[i][j]<49 || board[i][j]>57)
                    {
                        bool table_correct = false;
                        char k=49;
                        while(k<58 && !table_correct)
                        {
                            board[i][j] = k;
                            table_correct = complete_board(board,i,j);
                            k++;
                        }
                        if(!table_correct)
                        {
                            board[i][j] = '.';
                            return false;
                        }
                    }
                }
            }
            return true;
        }
        else
        {
            return false;
        }
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        complete_board(board,0,0);
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[i].size();j++)
            {
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};

int main()
{
    vector<vector<char>> board={{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};
    Solution sol;
    sol.solveSudoku(board);
    return 0;
}