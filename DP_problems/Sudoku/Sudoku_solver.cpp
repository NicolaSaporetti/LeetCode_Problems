#include <iostream>
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
    }
};