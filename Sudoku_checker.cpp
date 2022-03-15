#include "Sudoku_checker.hpp"
#include <vector>

using namespace std;

void Sudoku_checker::convertTableToMatrix(vector<vector<char>>& board, int table[][9])
{
    for(int i=0;i<board[i].size();i++)
    {
        for(int j=0;j<board[j].size();j++)
        {
            if(board[i][j]>=49 && board[i][j]<=57)
            {
                table[i][j] = board[i][j]-48;
            }
            else table[i][j] = 0;
        }
    }
}

bool Sudoku_checker::validateRows(int table[][9])
{
    bool isRowsValid = true;
    int checker[10] = {0};
    for(int i=0;i<9 && isRowsValid == true;i++)
    {
        int checker[10] = {0};
        for(int j=0;j<9;j++)
        {
            checker[table[i][j]]++;
        }
        for(int j=1;j<=9;j++)
        {
            if(checker[j]>1) isRowsValid = false;
            checker[j]= 0;
        }
    }
    return isRowsValid;
}

bool Sudoku_checker::validateColumns(int table[][9])
{
    bool isColumnsValid = true;
    int checker[10] = {0};
    for(int i=0;i<9 && isColumnsValid == true;i++)
    {
        
        for(int j=0;j<9;j++)
        {
            checker[table[j][i]]++;
        }
        for(int j=1;j<=9;j++)
        {
            if(checker[j]>1) isColumnsValid = false;
            checker[j]= 0;
        }
    }
    return isColumnsValid;
}

bool Sudoku_checker::validateBoxes(int table[][9])
{
    bool isBoxesValid = true;
    int checker[10] = {0};
    for(int i=0;i<3 && isBoxesValid == true;i++)
    {
        for(int t=0;t<3;t++)
        {
            for(int j=0;j<3;j++)
            {
                for(int w=0;w<3;w++)
                {
                    checker[table[i*3+j][t*3+w]]++;
                }
            }
            for(int j=1;j<=9;j++)
            {
                if(checker[j]>1) isBoxesValid = false;
                checker[j]= 0;
            }
        }
    }
    return isBoxesValid;
}

bool Sudoku_checker::isValidSudoku(vector<vector<char>>& board) {
    int table[9][9];
    convertTableToMatrix(board,table);
    return validateRows(table) && validateColumns(table) && validateBoxes(table);
}