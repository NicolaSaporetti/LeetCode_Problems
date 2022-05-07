#ifndef Queens_checker_HPP
#define Queens_checker_HPP
#include <vector>

using namespace std;

class Queens_checker {
private:
    int sz;
    vector<vector<bool>>* board;
    vector<vector<int>>* positions;
    bool validateRow(int row);
    bool validateRows();
    bool validateColumn(int column);
    bool validateColumns();
    bool validateDiagonal45(int row, int column);
    bool validateDiagonal135(int row, int column);
    bool validateDiagonals();
public:
    Queens_checker();
    Queens_checker(int sz, vector<vector<bool>>* board, vector<vector<int>>* positions);
    bool isValidQueens();
    bool addValidNewQueens(vector<int>& newPos);
    void removeLastValidQueen();
    void set(int sz, vector<vector<bool>>* board);
    int get_positions_size();
};
#endif