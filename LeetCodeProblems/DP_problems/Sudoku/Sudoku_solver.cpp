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

    Solution() : sudoku(9) {}
};

int main()
{
    vector<vector<char>> board={{'5', '3', '4', '6', '7', '8', '9', '1', '2'},
                                  {'6', '7', '2', '1', '9', '5', '3', '4', '8'},
                                  {'1', '9', '8', '3', '4', '2', '5', '6', '7'},
                                  {'8', '5', '9', '7', '6', '1', '4', '2', '3'},
                                  {'4', '2', '6', '8', '5', '3', '7', '9', '1'},
                                  {'7', '1', '3', '9', '2', '4', '8', '5', '6'},
                                  {'9', '6', '1', '5', '3', '7', '2', '8', '4'},
                                  {'2', '8', '7', '4', '1', '9', '6', '3', '5'},
                                  {'3', '4', '5', '2', '8', '6', '1', '7', '9'}};
    Solution solution;
    solution.solveSudoku(board);
    return 0;
}