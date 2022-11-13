#include <vector>
using namespace std;

class ValidSudoku {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        sz = board.size();
        checker.assign(9,0);
        return validateRows(board) && validateColumns(board) && validateBoxes(board);
    }
    
    bool isValidSudoku(vector<vector<char>>& board, int row, int column) {
        sz = board.size();
        return validateRow(board,row) && validateColumn(board,column) && validateBox(board, row, column);
    }

private:
    bool validateRows(vector<vector<char>>& board)
    {
        bool isRowsValid = true;
        for(int i=0;i<sz && isRowsValid;i++) isRowsValid = validateRow(board,i);
        return isRowsValid;
    }
    
    bool validateRow(vector<vector<char>>& board, int row)
    {
        checker.assign(9,0);
        for(int j=0;j<sz;j++) if(board[row][j]>='1' && board[row][j]<='9') checker[board[row][j]-'1']++;
        for(int j=0;j<sz;j++) if(checker[j]>1) return false;
        return true;
    }

    bool validateColumns(vector<vector<char>>& board)
    {
        bool isColumnValid = true;
        for(int i=0;i<sz && isColumnValid;i++) isColumnValid = validateColumn(board,i);
        return isColumnValid;
    }

    bool validateColumn(vector<vector<char>>& board, int column)
    {
        checker.assign(9,0);
        for(int j=0;j<sz;j++) if(board[j][column]>='1' && board[j][column]<='9') checker[board[j][column]-'1']++;
        for(int j=0;j<sz;j++) if(checker[j]>1) return false;
        return true;
    }

    bool validateBoxes(vector<vector<char>>& board)
    {
        bool isBoxesValid = true;
        for(int i=0;i<9 && isBoxesValid;i+=3)
            for(int t=0;t<9 && isBoxesValid;t+=3) isBoxesValid = validateBox(board,i,t);
        return isBoxesValid;
    }

    bool validateBox(vector<vector<char>>& board, int row, int column)
    {
        checker.assign(9,0);
        int rowBase = (row/3)*3;
        int colBase = (column/3)*3;
        for(int j=0;j<3;j++)
            for(int w=0;w<3;w++) if(board[rowBase+j][colBase+w]>='1' && board[rowBase+j][colBase+w]<='9') checker[board[rowBase+j][colBase+w]-'1']++;
        for(int j=0;j<sz;j++) if(checker[j]>1) return false;
        return true;
    }
    
    int sz;
    vector<int> checker;
};