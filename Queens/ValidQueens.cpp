#include <iostream>
#include <stdlib.h>
#include <vector>
#include "Queens_checker.cpp"

using namespace std;

int main()
{
    int n=3;
    vector<vector<bool>> board;
    vector<vector<int>> positions;
    for(int i=0;i<n;i++)
    {
        vector<bool> temp;
        for(int j=0;j<n;j++)
        {
            temp.push_back(false);
        }
        board.push_back(temp);
    }
    vector<int> a = {0,0};
    positions.push_back(a);
    board[a[0]][a[1]]= true;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    Queens_checker queens(n,&board, &positions);
    a[0] = 1;
    a[1] = 2;
    cout<<"Valid: "<<queens.addValidNewQueens(a)<<endl;
    cout<<"Size: "<<queens.get_positions_size()<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}