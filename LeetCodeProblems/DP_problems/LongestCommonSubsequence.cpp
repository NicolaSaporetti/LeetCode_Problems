#include <vector>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int rows = text1.size();
        int cols = text2.size();
        vector<vector<int>> board(rows+1,vector<int>(cols+1,0));
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(text1[i]==text2[j])
                {
                    board[i+1][j+1]=board[i][j]+1;
                }
                else
                {
                    board[i+1][j+1]=max(board[i][j+1],board[i+1][j]);
                }
            }
        }
        return board[rows][cols];
    }
};