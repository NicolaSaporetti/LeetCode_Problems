#include <iostream>
#include <stdlib.h>
#include <vector>
#include "Queens_checker.cpp"

using namespace std;

int main()
{
    int n=3;
    vector<vector<bool>> board;
    for(int i=0;i<n;i++)
    {
        vector<bool> temp;
        for(int j=0;j<n;j++)
        {
            temp.push_back(false);
        }
        board.push_back(temp);
    }
    board[0][1]= true;
    board[1][2]= true;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    Queens_checker queens(n,&board);
    cout<<"Board valid: "<<queens.isValidQueens();
    return 0;
}