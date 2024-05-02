#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        sz = n;
        graphToLeafs = buildDirectGraphToLeafs(edges,n);
        vector<int> graphToRoot = buildDirectGraphToRoot(graphToLeafs,n);
        vector<int> children(n);
        w.assign(n,1);
        r.resize(n);
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            children[i]=graphToLeafs[i].size();
            if(!children[i]) q.push(i);
        }
        while(!q.empty())
        {
            int el = q.front();
            q.pop();
            int parent = graphToRoot[el];
            if(parent!=-1)
            {
                children[parent]--;
                if(!children[parent]) q.push(parent);
                w[parent]+=w[el];
                r[parent]+=r[el]+w[el];
            }
        }
        traverse(0, -1);
        return r;
    }
private:
    void traverse(int node, int parent)
    {
        if(parent!=-1) r[node]=r[parent]+(sz-2*w[node]);
        for(int i=0;i<graphToLeafs[node].size();i++) traverse(graphToLeafs[node][i],node);
    }

    vector<int> w;
    vector<int> r;
    vector<vector<int>> graphToLeafs;
    int sz;
};