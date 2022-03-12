#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

class Solution {
    private:
    void convertTableToMatrix(vector<vector<char>>& board, int table[][9])
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
                cout<<" "<<table[i][j];
            }
            cout<<endl;
        }
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool result = true;
        int table[9][9];
        convertTableToMatrix(board,table);
        for(int i=0;i<9 && result == true;i++)
        {
            int checker[10] = {0};
            //ROW
            for(int j=0;j<9;j++)
            {
                checker[table[i][j]]++;
            }
            for(int j=1;j<=9;j++)
            {
                if(checker[j]>1) result = false;
                //cout<<"Number "<<j<<" result "<<result<<endl;
                checker[j]= 0;
            }

            //COLUMN
            for(int j=0;j<9;j++)
            {
                checker[table[j][i]]++;
            }
            for(int j=1;j<=9;j++)
            {
                if(checker[j]>1) result = false;
                checker[j]= 0;
            }
        }
        for(int i=0;i<3 && result == true;i++)
        {
            for(int t=0;t<3;t++)
            {
                int checker[10] = {0};
                //SQUARE
                for(int j=0;j<3;j++)
                {
                    for(int w=0;w<3;w++)
                    {
                        checker[table[i*3+j][t*3+w]]++;
                    }
                }
                for(int j=1;j<=9;j++)
                {
                    if(checker[j]>1) result = false;
                    checker[j]= 0;
                }
                cout<<endl;
            }
        }
        return result;
    }
};

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
    Solution solution;
    cout<<solution.isValidSudoku(board)<<endl;
    return 0;
}