#include <vector>
#include <array>

using namespace std;

class Sudoku_checker {
private:
    int sz;
    array<int, 9> checker;
    void resetChecker();
    bool validateRow(vector<vector<char>>& board, int row);
    bool validateRows(vector<vector<char>>& board);
    bool validateColumn(vector<vector<char>>& board, int column);
    bool validateColumns(vector<vector<char>>& board);
    bool validateBoxe(vector<vector<char>>& board, int boxRow, int boxColumn);
    bool validateBoxes(vector<vector<char>>& board);
public:
    Sudoku_checker();
    bool isValidSudoku(vector<vector<char>>& board);
    bool isValidSudoku(vector<vector<char>>& board, int row, int column);
};