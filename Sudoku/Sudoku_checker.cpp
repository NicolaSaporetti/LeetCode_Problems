#include "Sudoku_checker.hpp"
#include <vector>
using namespace std;

Sudoku_checker::Sudoku_checker()
{
    sz=9;
}

void Sudoku_checker::resetChecker()
{
    for(int i=0;i<sz;i++)
    {
        checker[i]=0;
    }
}

bool Sudoku_checker::validateRow(vector<vector<char>>& board, int row)
{
    bool isRowsValid = true;
    resetChecker();
    for(int j=0;j<sz;j++)
    {
        if(board[row][j]>=49 && board[row][j]<=57)
        {
            checker[board[row][j]-49]++;
        }
    }
    for(int j=0;j<sz && isRowsValid;j++)
    {
        if(checker[j]>1) isRowsValid = false;
    }
    return isRowsValid;
}

bool Sudoku_checker::validateRows(vector<vector<char>>& board)
{
    bool isRowsValid = true;
    for(int i=0;i<sz && isRowsValid;i++)
    {
        resetChecker();
        isRowsValid=validateRow(board,i);
    }
    return isRowsValid;
}

bool Sudoku_checker::validateColumn(vector<vector<char>>& board, int column)
{
    bool isColumnsValid = true;
    resetChecker();
    for(int j=0;j<sz;j++)
    {
        if(board[j][column]>=49 && board[j][column]<=57)
        {
            checker[board[j][column]-49]++;
        }
    }
    for(int j=0;j<sz && isColumnsValid;j++)
    {
        if(checker[j]>1) isColumnsValid = false;
    }
    return isColumnsValid;
}

bool Sudoku_checker::validateColumns(vector<vector<char>>& board)
{
    bool isColumnsValid = true;
    for(int i=0;i<sz && isColumnsValid;i++)
    {
        resetChecker();
        isColumnsValid = validateColumn(board,i);
    }
    return isColumnsValid;
}

bool Sudoku_checker::validateBoxe(vector<vector<char>>& board, int boxRow, int boxColumn)
{
    bool isBoxesValid = true;
    resetChecker();
    for(int j=0;j<3;j++)
    {
        for(int w=0;w<3;w++)
        {
            if(board[boxRow*3+j][boxColumn*3+w]>=49 && board[boxRow*3+j][boxColumn*3+w]<=57)
            {
                checker[board[boxRow*3+j][boxColumn*3+w]-49]++;
            }
        }
    }
    for(int j=0;j<sz && isBoxesValid;j++)
    {
        if(checker[j]>1) isBoxesValid = false;
    }
    return isBoxesValid;
}

bool Sudoku_checker::validateBoxes(vector<vector<char>>& board)
{
    bool isBoxesValid = true;
    for(int i=0;i<3 && isBoxesValid;i++)
    {
        for(int t=0;t<3;t++)
        {
            isBoxesValid = validateBoxe(board,i,t);
        }
    }
    return isBoxesValid;
}

bool Sudoku_checker::isValidSudoku(vector<vector<char>>& board) {
    return validateRows(board) && validateColumns(board) && validateBoxes(board);
}

bool Sudoku_checker::isValidSudoku(vector<vector<char>>& board, int row, int column) {
    return validateRow(board, row) && validateColumn(board, column) && validateBoxe(board, row/3, column/3);
}