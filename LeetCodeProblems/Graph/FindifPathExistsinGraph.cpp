#include <vector>
#include <set>
#include <queue>
using namespace std;

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<set<int>> m(n);
        vector<vector<int>> res(n);
        for(auto e : edges)
        {
            m[e[0]].insert(e[1]);
            m[e[1]].insert(e[0]);
        }
        queue<int> q;
        q.push(source);
        while(!q.empty())
        {
            int el = q.front();
            q.pop();
            if(el==destination) return true;
            for(auto e : m[el])
            {
                m[e].erase(el);
                q.push(e);
            }
        }
        return false;
    }
};