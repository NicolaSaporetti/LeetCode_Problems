class Solution {
private:
    int row_sz;
    int col_sz;
    
    void markSafeRegions(int row, int col, vector<vector<char>>& board)
    {
        if(board[row][col]=='O')
        {
            board[row][col] = 'Y';
            if(row-1>=0) markSafeRegions(row-1,col,board);
            if(row+1<row_sz) markSafeRegions(row+1,col,board);
            if(col-1>=0) markSafeRegions(row,col-1,board);
            if(col+1<col_sz) markSafeRegions(row,col+1,board);
        }
    }
    
    void flipRegions(vector<vector<char>>& board)
    {
        for(int i=0;i<row_sz;i++)
        {
            for(int j=0;j<col_sz;j++)
            {
                if(board[i][j]=='O') board[i][j]='X';
                if(board[i][j]=='Y') board[i][j]='O';
            }
        }
    }
    
public:
    void solve(vector<vector<char>>& board) {
        row_sz = board.size();
        col_sz = board[0].size();
        for(int i=0;i<col_sz;i++)
        {
            markSafeRegions(0,i,board);
            markSafeRegions(row_sz-1,i,board);
        }
        for(int i=1;i<row_sz-1;i++)
        {
            markSafeRegions(i,0,board);
            markSafeRegions(i,col_sz-1,board);
        }
        flipRegions(board);
    }
};