#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> toL = buildDirectGraphToLeafs(edges, n);
        vector<int> toR = buildDirectGraphToRoot(toL,n);
        vector<vector<int>> v(n,vector<int>(26,0));
        vector<int> out(n,0);
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            out[i]=toL[i].size();
            if(out[i]==0) q.push(i);
        }
        vector<int> r(n,0);
        while(!q.empty())
        {
            int el = q.front();
            q.pop();
            v[el][labels[el]-'a']++;
            if(toR[el]!=-1)
            {
                int top = toR[el];
                out[top]--;
                if(out[top]==0) q.push(top);
                for(int i=0;i<26;i++) v[top][i]+=v[el][i];
            }
            r[el]=v[el][labels[el]-'a'];
        }
        return r;
    }
};