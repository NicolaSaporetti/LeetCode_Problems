#include <vector>
using namespace std;

class Solution {
public:
    bool placeWordInCrossword(vector<vector<char>>& board, string word) {
        rz = board.size();
        cz = board[0].size();
        return computeHorizontalRight(board,word) || computeHorizontalLeft(board,word) || 
               computeVerticalBottom(board,word) || computeVerticalTop(board,word);
    }
                                                                           
private:
    bool computeHorizontalRight(vector<vector<char>>& board, string& word)
    {
        for(int i=0;i<rz;i++)
        {
            int wp = 0;
            for(int j=0;j<cz;j++)
            {
                if(board[i][j]=='#')
                {
                    if(wp == word.size()) return true;
                    else wp = 0;
                }
                else if(wp<word.size() && (board[i][j]==' ' || board[i][j]==word[wp])) wp++;
                else
                {
                    wp = 0;
                    while(++j<cz && board[i][j]!='#');
                }
            }
            if(wp == word.size()) return true;
        }
        return false;
    }
    
    bool computeHorizontalLeft(vector<vector<char>>& board, string& word)
    {
        for(int i=0;i<rz;i++)
        {
            int wp = 0;
            for(int j=cz-1;j>=0;j--)
            {
                if(board[i][j]=='#')
                {
                    if(wp == word.size()) return true;
                    else wp = 0;
                }
                else if(wp<word.size() && (board[i][j]==' ' || board[i][j]==word[wp])) wp++;
                else
                {
                    wp = 0;
                    while(--j>=0 && board[i][j]!='#');
                }
            }
            if(wp == word.size()) return true;
        }
        return false;
    }
    
    bool computeVerticalBottom(vector<vector<char>>& board, string& word)
    {
        for(int j=0;j<cz;j++)
        {
            int wp = 0;
            for(int i=0;i<rz;i++)
            {
                if(board[i][j]=='#')
                {
                    if(wp == word.size()) return true;
                    else wp = 0;
                }
                else if(wp<word.size() && (board[i][j]==' ' || board[i][j]==word[wp])) wp++;
                else
                {
                    wp = 0;
                    while(++i<rz && board[i][j]!='#');
                }
            }
            if(wp == word.size()) return true;
        }
        return false;
    }
    
    bool computeVerticalTop(vector<vector<char>>& board, string& word)
    {
        for(int j=0;j<cz;j++)
        {
            int wp = 0;
            for(int i=rz-1;i>=0;i--)
            {
                if(board[i][j]=='#')
                {
                    if(wp == word.size()) return true;
                    else wp = 0;
                }
                else if(wp<word.size() && (board[i][j]==' ' || board[i][j]==word[wp])) wp++;
                else
                {
                    wp = 0;
                    while(--i>=0 && board[i][j]!='#');
                }
            }
            if(wp == word.size()) return true;
        }
        return false;
    }
                                                                           
    int rz,cz;
};