#include <iostream>
#include <stdlib.h>
#include <vector>
#include "Sudoku_checker.cpp"

using namespace std;

int main()
{
    vector<vector<char>> board;
    for(int i=0;i<9;i++)
    {
        vector<char> row  = {'.','.','.','.','5','.','.','1','.'};
        board.push_back(row);
        vector<char> row1 = {'.','4','.','3','.','.','.','.','.'};
        board.push_back(row1);
        vector<char> row2 = {'.','.','.','.','.','3','.','.','1'};
        board.push_back(row2);
        vector<char> row3 = {'8','.','.','.','.','.','.','2','.'};
        board.push_back(row3);
        vector<char> row4 = {'.','.','2','.','7','.','.','.','.'};
        board.push_back(row4);
        vector<char> row5 = {'.','1','5','.','.','.','.','.','.'};
        board.push_back(row5);
        vector<char> row6 = {'.','.','.','.','.','2','.','.','.'};
        board.push_back(row6);
        vector<char> row7 = {'.','2','.','9','.','.','.','.','.'};
        board.push_back(row7);
        vector<char> row8 = {'.','.','4','.','.','.','.','.','.'};
        board.push_back(row8);
    }
    Sudoku_checker sudoku;
    cout<<sudoku.isValidSudoku(board)<<endl;
    return 0;
}