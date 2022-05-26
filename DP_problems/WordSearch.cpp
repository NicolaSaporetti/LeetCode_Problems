#include <iostream>
using namespace std;

class Solution {
private:
    int rows;
    int cols;
    bool solve(vector<vector<char>>& board, string& word, int currentLetter, int row, int col)
    {
        for(int i=0;i<currentLetter;i++) cout<<word[i];
        cout<<endl;
        cout<<"New letter: "<<word[currentLetter]<<",   Row: "<<row<<", Col: "<<col<<endl;
        if(board[row][col]==word[currentLetter])
        {
            if(word.size()-1>currentLetter)
            {
                bool res = false;
                if(row-1>=0) res|= solve(board, word, currentLetter+1, row-1, col);
                if(row+1<rows && !res) res|= solve(board, word, currentLetter+1, row+1, col);
                if(col-1>=0 && !res) res|= solve(board, word, currentLetter+1, row, col-1);
                if(col+1<cols && !res) res|= solve(board, word, currentLetter+1, row, col+1);
                return res;
            }
            else return true;
        }
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        rows = board.size();
        cols = board[0].size();
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(solve(board, word, 0, i, j)) return true;
            }
        }
        return false;
    }
};

int main()
{
    Solution solution;
    return 0;
}