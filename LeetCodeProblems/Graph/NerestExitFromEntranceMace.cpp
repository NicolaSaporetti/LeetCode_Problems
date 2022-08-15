#include <iostream>
#include <vector>
#include <priority_queue>
using namespace std;

class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();
        queue<pair<int,int>> q;
        int i = entrance[0];
        int j = entrance[1];
        if(i>0 && maze[i-1][j]=='.') q.push({entrance[0]-1,entrance[1]});
        if(j>0 && maze[i][j-1]=='.') q.push({entrance[0],entrance[1]-1});
        if(i<n-1 && maze[i+1][j]=='.') q.push({entrance[0]+1,entrance[1]});
        if(j<m-1 && maze[i][j+1]=='.') q.push({entrance[0],entrance[1]+1});
        
        maze[entrance[0]][entrance[1]] = '+';
        
        vector<vector<int>> dir = {{1,0},{0,1},{-1,0},{0,-1}};
        int steps = 0;
        
        while(!q.empty()){
            int s = q.size();
            steps++;
            for(int k=0;k<s;k++){
                int curx = q.front().first;
                int cury = q.front().second;
                q.pop();
                
                if(curx==0 || cury==0 || curx==n-1 || cury==m-1) return steps;
                for(auto it:dir){
                    int x = curx+it[0];
                    int y = cury+it[1];
                    
                    if(maze[x][y]=='.'){
                        maze[x][y] = '+';
                        q.push({x,y});
                    }
                }
            }
        }
        return -1;
    }
};