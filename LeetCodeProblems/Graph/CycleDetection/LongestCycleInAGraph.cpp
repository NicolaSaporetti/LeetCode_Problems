#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int longestCycle(vector<int>& edges) {
        unordered_set<int> s = removeElementNotInCycle(edges);
        int res = -1;
        while(!s.empty())
        {
            int first = *s.begin();
            s.erase(first);
            int num = 1;
            int el = first;
            do
            {
                el = edges[el];
                s.erase(el);
                num++;
            } while(edges[el]!=first);
            res = max(res,num);
        }
        return res;
    }
private:
    unordered_set<int> removeElementNotInCycle(vector<int>& edges)
    {
        unordered_set<int> s;
        int res = 0;
        int sz = edges.size();
        vector<int> v(sz,0);
        for(auto e : edges) if(e!=-1) v[e]++;
        queue<int> q;
        for(int i=0;i<sz;i++) if(v[i]==0) q.push(i);
        while(!q.empty())
        {
            int el = q.front();
            q.pop();
            if(edges[el]!=-1)
            {
                v[edges[el]]--;
                if(!v[edges[el]]) q.push(edges[el]);
            }
        }
        for(int i=0;i<sz;i++)
            if(v[i]!=0) s.insert(i);
        return s;
    }
};