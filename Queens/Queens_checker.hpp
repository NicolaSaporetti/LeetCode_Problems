#ifndef Queens_checker_HPP
#define Queens_checker_HPP
#include <vector>

using namespace std;

class Queens_checker {
private:
    int sz;
    vector<vector<bool>>* board;
    bool rowIsEmpty(int row);
    bool validateRow(int row);
    bool validateRows();
    bool columnIsEmpty(int column);
    bool validateColumn(int column);
    bool validateColumns();
    bool IsDiagonal45Empty(int row, int column);
    bool validateDiagonal45(int row, int column);
    bool IsDiagonal135Empty(int row, int column);
    bool validateDiagonal135(int row, int column);
    bool validateDiagonals();
public:
    Queens_checker();
    Queens_checker(int sz, vector<vector<bool>>* board);
    bool isValidQueens();
    bool isNewQueensValid(int row, int column);
    void set(int sz, vector<vector<bool>>* board);
};
#endif