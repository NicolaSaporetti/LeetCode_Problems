#include <vector>
using namespace std;

class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int sz = bombs.size();
        vector<bool> visited;
        int res = 0;
        for(int i=0;i<sz;i++)
        {
            visited.assign(sz,false);
            int val = 0;
            queue<int> q;
            q.push(i);
            visited[i]=true;
            while(!q.empty())
            {
                val++;
                int b1 = q.front();
                q.pop();
                for(int j=0;j<sz;j++)
                {
                    if(!visited[j] && isBombWithinRadius(b1,j,bombs))
                    {
                        q.push(j);
                        visited[j]=true;
                    }
                }
            }
            res = max(res,val);
        }
        return res;
    }
private:
    bool isBombWithinRadius(int b1, int b2, vector<vector<int>>& bombs)
    {
        long long x = abs(bombs[b1][0]-bombs[b2][0]);
        long long y = abs(bombs[b1][1]-bombs[b2][1]);
        long r1 = (long long)bombs[b1][2]*(long long)bombs[b1][2];
        return r1>=(x*x+y*y);
    }
};