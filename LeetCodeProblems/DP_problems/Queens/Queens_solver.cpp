#include <iostream>
#include <vector>
#include <array>
#include "Queens_checker.cpp"

using namespace std;

class Solution {
private:
    Queens_checker queens_checker;
    vector<vector<bool>> board;
    vector<vector<string>> solutions;
    int n;
    int total;
    void convertBoardToSolution()
    {
        vector<string> currentSol;
        for(int i=0;i<n;i++)
        {
            string temp;
            for(int j=0;j<n;j++)
            {
                if(!board[i][j]) temp.push_back('.');
                else temp.push_back('Q');

            }
            currentSol.push_back(temp);
        }
        solutions.push_back(currentSol);
    }
    void complete_board(int x)
    {
        if(x==n){
            total++;
            convertBoardToSolution();
            return;
        }
        
        for(int i=0;i<n;i++){
            if(queens_checker.isNewQueensValid(x,i)){
                board[x][i]=true;
                complete_board(x+1);
                board[x][i]=false;
            }
        }
    }

public:
    int totalNQueens(int n) {
        this->n=n;
        total = 0;
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
        complete_board(0);
        for(int k=0;k<solutions.size();k++)
        {
            for(int i=0;i<n;i++)
            {
                cout<<solutions[k][i]<<endl;
            }
            cout<<endl;
        }
        return total;
    }
};

int main()
{
    Solution sol;
    int value = sol.totalNQueens(6);
    cout<<"Solution: "<<value<<endl;
    return 0;
}