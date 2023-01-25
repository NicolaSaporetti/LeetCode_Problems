#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int result = 0;
        n = board.size();
        vector<int> v = computeVector(board);
        vector<bool> vis(n*n,false);
        queue<int> q;
        int step = 0;
        q.push(0);
        vis[0]=true;
        while(!q.empty())
        {
            step++;
            int num = q.size();
            for(int j=0;j<num;j++)
            {
                int elem = q.front();
                q.pop();
                for(int i=1;i<=6 && elem+i<n*n;i++)
                {
                    int newEl = elem+i;
                    if(v[newEl]!=-2) newEl = v[newEl];
                    if(!vis[newEl])
                    {
                        vis[newEl]=true;
                        if(newEl ==n*n-1) return step;
                        q.push(newEl);
                    }
                }
            }
        }
        return -1;
    }
private:
    vector<int> computeVector(vector<vector<int>>& board)
    {
        vector<int> v(n*n);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            {
                if(i%2==1)  v[i*n+j]=board[n-1-i][n-1-j]-1;
                else v[i*n+j]=board[n-1-i][j]-1;
            }
        return v;
    }

    int n;
};