#include "Queens_checker.hpp"
#include <vector>
using namespace std;

Queens_checker::Queens_checker(): sz(0), board(nullptr)
{}

Queens_checker::Queens_checker(int sz, vector<vector<bool>>* board): sz(sz), board(board)
{}

void Queens_checker::set(int sz, vector<vector<bool>>* board)
{
    this->sz=sz;
    this->board=board;
}

bool Queens_checker::rowIsEmpty(int row)
{
    for(int j=0;j<sz;j++)
    {
        if((*board)[row][j]) return false;
    }
    return true;
}

bool Queens_checker::validateRow(int row)
{
    int number=0;
    bool isRowsValid = true;
    for(int j=0;j<sz;j++)
    {
        if((*board)[row][j]) number++;
    }
    if(number>=2) isRowsValid = false;
    return isRowsValid;
}

bool Queens_checker::validateRows()
{
    for(int i=0;i<sz;i++)
    {
        if(!validateRow(i)) return false;
    }
    return true;
}

bool Queens_checker::columnIsEmpty(int column)
{
    for(int j=0;j<sz;j++)
    {
        if((*board)[j][column]) return false;
    }
    return true;
}

bool Queens_checker::validateColumn(int column)
{
    int number=0;
    bool isRowsValid = true;
    for(int j=0;j<sz;j++)
    {
        if((*board)[j][column]) number++;
    }
    if(number>=2) isRowsValid = false;
    return isRowsValid;
}

bool Queens_checker::validateColumns()
{
    for(int i=0;i<sz;i++)
    {
        if(!validateColumn(i)) return false;
    }
    return true;
}

bool Queens_checker::IsDiagonal45Empty(int row, int column)
{
    for(int i=0;row-i>=0 && column+i<sz;i++)
    {
        if((*board)[row-i][column+i]) return false;
    }
    for(int i=1;row+i<sz && column-i>=0;i++)
    {
        if((*board)[row+i][column-i]) return false;
    }
    return true;
}

bool Queens_checker::validateDiagonal45(int row, int column)
{
    int number=0;
    bool isDiagonalValid = true;
    for(int i=0;row-i>=0 && column+i<sz;i++)
    {
        if((*board)[row-i][column+i]) number++;
    }
    for(int i=1;row+i<sz && column-i>=0;i++)
    {
        if((*board)[row+i][column-i]) number++;
    }
    if(number>=2) isDiagonalValid = false;
    return isDiagonalValid;
}

bool Queens_checker::IsDiagonal135Empty(int row, int column)
{
    for(int i=0;row-i>=0 && column-i>=0;i++)
    {
        if((*board)[row-i][column-i]) return false;
    }
    for(int i=1;row+i<sz && column+i<sz;i++)
    {
        if((*board)[row+i][column+i]) return false;
    }
    return true;
}

bool Queens_checker::validateDiagonal135(int row, int column)
{
    //cout<<"Diagonal135"<<endl;
    int number=0;
    bool isDiagonalValid = true;
    for(int i=0;row-i>=0 && column-i>=0 && isDiagonalValid;i++)
    {
        if((*board)[row-i][column-i]) number++;
    }
    for(int i=1;row+i<sz && column+i<sz && isDiagonalValid;i++)
    {
        if((*board)[row+i][column+i]) number++;
    }
    if(number>=2) isDiagonalValid = false;
    return isDiagonalValid;
}

bool Queens_checker::validateDiagonals()
{
    for(int i=0;i<sz;i++)
    {
        if(!validateDiagonal45(i, 0)) return false;
    }
    for(int i=1;i<sz;i++)
    {
        if(!validateDiagonal45(sz-1, i)) return false;
    }
    for(int i=0;i<sz;i++)
    {
        if(!validateDiagonal135(0, i)) return false;
    }
    for(int i=1;i<sz;i++)
    {
        if(!validateDiagonal135(i, 0)) return false;
    }
    return true;
}

bool Queens_checker::isValidQueens() {
    return validateRows() && validateColumns() && validateDiagonals();
}

bool Queens_checker::isNewQueensValid(int row, int column) {
    bool newQueenValid = false;
    if(!(*board)[row][column])
    {
        newQueenValid = rowIsEmpty(row) && columnIsEmpty(column) && IsDiagonal45Empty(row,column) && IsDiagonal135Empty(row,column);
    }
    return newQueenValid;
}