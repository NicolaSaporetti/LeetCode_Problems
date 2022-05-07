#include <iostream>
#include <stdlib.h>
#include <vector>
#include "Queens_checker.cpp"

using namespace std;

class Solution {
private:
    Queens_checker queens_checker;
    vector<vector<bool>> board;
    vector<vector<int>> positions;
    int n;
    int total;
    int localTotal;
    void complete_board(vector<int>& newPos)
    {
        cout<<"New pos to try: "<<newPos[0]<<" "<<newPos[1]<<endl;
        if(queens_checker.addValidNewQueens(newPos))
        {
            if(queens_checker.get_positions_size()==n)
            {
                total++;
                return;
            }
            if(newPos[1]==n-1)
            {
                newPos[0]++;
                newPos[1]=0;
            }
            else{
                newPos[1]++;
            }
            int j=newPos[1];
            for(int i=newPos[0];i<n;i++)
            {
                cout<<"i: "<<i<<endl;
                for(;j<n;j++)
                {
                    cout<<"j: "<<j<<endl;
                    newPos[0] = i;
                    newPos[1] = j;
                    complete_board(newPos);
                }
                j=0;
            }
            if(localTotal<queens_checker.get_positions_size()) localTotal = queens_checker.get_positions_size();
            queens_checker.removeLastValidQueen();
        }
    }

public:
    int totalNQueens(int n) {
        vector<int> newPos = {0,0};
        this->n=n;
        total = 0;
        localTotal = 0;
        for(int i=0;i<n;i++)
        {
            vector<bool> temp;
            for(int j=0;j<n;j++)
            {
                temp.push_back(false);
            }
            board.push_back(temp);
        }
        queens_checker.set(n,&board);
        complete_board(newPos);
        return localTotal;
    }
};

int main()
{
    Solution sol;
    int value = sol.totalNQueens(9);
    cout<<"Solution: "<<value<<endl;
    return 0;
}