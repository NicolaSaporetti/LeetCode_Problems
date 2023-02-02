#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int> in(n);
        vector<vector<int>> out(n);
        vector<int> add(n,0);
        queue<int> q;
        for(auto& r : relations)
        {
            in[r[1]-1]++;
            out[r[0]-1].push_back(r[1]-1);
        }
        for(int i=0;i<n;i++) if(in[i]==0) q.push(i);
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            for(auto& connected : out[node])
            {
                add[connected] = max(add[connected],time[node]);
                in[connected]--;
                if(in[connected]==0)
                {
                    q.push(connected);
                    time[connected]+=add[connected];
                }
            }
        }
        return *max_element(begin(time),end(time));
    }
};