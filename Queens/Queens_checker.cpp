#include "Queens_checker.hpp"
#include <vector>
using namespace std;

Queens_checker::Queens_checker(): sz(0), board(nullptr), positions(nullptr)
{}

Queens_checker::Queens_checker(int sz, vector<vector<bool>>* board, vector<vector<int>>* positions): sz(sz), board(board), positions(positions)
{}

void Queens_checker::set(int sz, vector<vector<bool>>* board)
{
    this->sz=sz;
    this->board=board;
    this->positions=new vector<vector<int>>();
}

int Queens_checker::get_positions_size()
{
    return positions->size();
}

bool Queens_checker::validateRow(int row)
{
    int number=0;
    bool isRowsValid = true;
    cout<<"Row"<<endl;
    for(int j=0;j<sz;j++)
    {
        if((*board)[row][j]) number++;
    }
    if(number>=2) isRowsValid = false;
    return isRowsValid;
}

bool Queens_checker::validateRows()
{
    cout<<"Rows"<<endl;
    bool isRowsValid = true;
    for(int i=0;i<(*positions).size() && isRowsValid;i++)
    {
        isRowsValid=validateRow((*positions)[i][0]);
    }
    cout<<"isRowsValid: "<<isRowsValid<<endl;
    return isRowsValid;
}

bool Queens_checker::validateColumn(int column)
{
    int number=0;
    bool isRowsValid = true;
    cout<<"Column"<<endl;
    for(int j=0;j<sz;j++)
    {
        if((*board)[j][column]) number++;
    }
    if(number>=2) isRowsValid = false;
    return isRowsValid;
}

bool Queens_checker::validateColumns()
{
    cout<<"Column"<<endl;
    bool isColumnsValid = true;
    for(int i=0;i<(*positions).size() && isColumnsValid;i++)
    {
        isColumnsValid = validateColumn((*positions)[i][1]);
    }
    cout<<"isColumnsValid: "<<isColumnsValid<<endl;
    return isColumnsValid;
}

bool Queens_checker::validateDiagonal45(int row, int column)
{
    cout<<"Diagonal45"<<endl;
    int number=0;
    bool isDiagonalValid = true;
    for(int i=0;row-i>=0 && column+i<sz && isDiagonalValid;i++)
    {
        if((*board)[row-i][column+i]) number++;
    }
    if(number>=2) isDiagonalValid = false;
    return isDiagonalValid;
}

bool Queens_checker::validateDiagonal135(int row, int column)
{
    cout<<"Diagonal135"<<endl;
    int number=0;
    bool isDiagonalValid = true;
    for(int i=0;row-i>=0 && column-i>=0 && isDiagonalValid;i++)
    {
        if((*board)[row-i][column-i]) number++;
    }
    if(number>=2) isDiagonalValid = false;
    return isDiagonalValid;
}

bool Queens_checker::validateDiagonals()
{
    cout<<"Diagonal"<<endl;
    bool isDiagonalsValid = true;
    for(int i=0;i<(*positions).size() && isDiagonalsValid;i++)
    {
        isDiagonalsValid=validateDiagonal45((*positions)[i][0], (*positions)[i][1]);
    }
    cout<<"isDiagonalsValid: "<<isDiagonalsValid<<endl;
    for(int i=0;i<(*positions).size() && isDiagonalsValid;i++)
    {
        isDiagonalsValid=validateDiagonal135((*positions)[i][0], (*positions)[i][1]);
    }
    cout<<"isDiagonalsValid: "<<isDiagonalsValid<<endl;
    return isDiagonalsValid;
}

bool Queens_checker::isValidQueens() {
    return validateRows() && validateColumns() && validateDiagonals();
}

bool Queens_checker::addValidNewQueens(vector<int>& newPos) {
    bool newQueenValid = false;
    cout<<"Checking new queen position is valid: "<<newPos[0]<<" "<<newPos[1]<<endl;
    if(!(*board)[newPos[0]][newPos[1]])
    {
        (*board)[newPos[0]][newPos[1]]=true;
        newQueenValid = validateRow(newPos[0]) && validateColumn(newPos[1]) && validateDiagonal45(newPos[0],newPos[1]) && validateDiagonal135(newPos[0],newPos[1]);
        
        if(newQueenValid)
        {
            cout<<"updating boards"<<endl;
            (*board)[newPos[0]][newPos[1]] = true;
            for(int i=0;i<sz;i++)
            {
                for(int j=0;j<sz;j++)
                {
                    cout<<(*board)[i][j]<<" ";
                }
                cout<<endl;
            }
            cout<<"updating pos"<<endl;
            (*positions).push_back(newPos);
            cout<<"New size: "<<get_positions_size()<<endl;
        }
        else{
            cout<<"Position invalid"<<endl;
            (*board)[newPos[0]][newPos[1]]=false;
        }
    }
    return newQueenValid;
}

void Queens_checker::removeLastValidQueen() {
    if(get_positions_size()>=0)
    {
        int row = (*positions)[get_positions_size()-1][0];
        int column = (*positions)[get_positions_size()-1][1];
        if(!(*board)[row][column]) cout<<"ERROR, cell was supposed to be full"<<endl;
        (*board)[row][column]=false;
        positions->resize(get_positions_size()-1);
    }
}
