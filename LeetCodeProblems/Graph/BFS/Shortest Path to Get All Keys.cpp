#include <vector>
#include <array>
#include <queue>
using namespace std;

class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        array<int,4> dx = {1,-1,0,0};
        array<int,4> dy = {0,0,1,-1};
        rz=grid.size();
        cz=grid[0].size();
        int keys = get_final_key(grid);
        vector<vector<vector<bool>>> vis(keys, vector<vector<bool>>(rz,vector<bool>(cz,false)));
        int res = 0;

        q.push(get_starting(grid));
        vis[q.front()[2]][q.front()[0]][q.front()[1]] = true;
        while(!q.empty())
        {
            int n = q.size();
            for(int i=0;i<n;i++)
            {
                auto el = q.front();
                q.pop();
                if(el[2]==keys-1) return res;
                for(int i=0;i<4;i++)
                {
                    int nx = el[0]+dx[i];
                    int ny = el[1]+dy[i];
                    int key = el[2];
                    if(nx>=0 && nx<rz && ny>=0 && ny<cz)
                    {
                        if(grid[nx][ny]>='a' && grid[nx][ny]<='f')
                        {
                            key |= (1<<(grid[nx][ny]-'a'));
                        }
                        if(vis[key][nx][ny]) continue;
                        if(grid[nx][ny]>='A' && grid[nx][ny]<='F')
                        {
                            if(key & (1<<(grid[nx][ny]-'A')))
                            {
                                q.push({nx,ny,key});
                                vis[key][nx][ny]=true;
                            }
                        }
                        else if(grid[nx][ny]!='#')
                        {
                            q.push({nx,ny,key});
                            vis[key][nx][ny]=true;
                        }
                    }
                }
            }
            res++;
        } 
        return -1;
    }
private:
    int get_final_key(vector<string>& grid)
    {
        vector<bool> keys(6,0);
        for(int i=0;i<rz;i++)
            for(int j=0;j<cz;j++)
                if(grid[i][j]>='a' && grid[i][j]<='f') keys[grid[i][j]-'a']=true;
        int num = 0;
        for(int i=0;i<6;i++) if(keys[i]) num++;
        return pow(2,num);
    }

    vector<int> get_starting(vector<string>& grid)
    {
        vector<int> result;
        for(int i=0;i<rz;i++)
            for(int j=0;j<cz;j++)
                if(grid[i][j]=='@')
                {
                    result = {i,j,0};
                    break;
                }
        return result;
    }

    queue<vector<int>> q;
    int rz;
    int cz;
};