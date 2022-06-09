#include <iostream>
#include <vector>
#include "Sudoku_checker.cpp"

using namespace std;

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
    Sudoku_checker sudoku;
    cout<<sudoku.isValidSudoku(board)<<endl;
    return 0;
}