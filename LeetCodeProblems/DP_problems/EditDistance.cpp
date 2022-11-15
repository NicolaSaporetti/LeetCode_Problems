#include <vector>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int rows = word1.size();
        int cols = word2.size();
        vector<vector<int>> board(rows+1,vector<int>(cols+1,0));
        for(int i=0;i<rows+1;i++)
        {
            board[i][0] = i;
        }
        for(int i=0;i<cols+1;i++)
        {
            board[0][i] = i;
        }
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(word1[i]==word2[j])
                {
                    board[i+1][j+1]=board[i][j];
                }
                else
                {
                    board[i+1][j+1]=1+min(board[i+1][j],min(board[i][j+1],board[i][j]));
                }
            }
        }
        return board[rows][cols];
    }
};