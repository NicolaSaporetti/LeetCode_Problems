#include <vector>
using namespace std;

class Sudoku_checker {
private:
    void convertTableToMatrix(vector<vector<char>>& board, int table[][9]);
    bool validateRows(int table[][9]);
    bool validateColumns(int table[][9]);
    bool validateBoxes(int table[][9]);
public:
    bool isValidSudoku(vector<vector<char>>& board);
};