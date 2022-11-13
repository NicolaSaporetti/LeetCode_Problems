vector<vector<int>> buildDirectGraphToLeafs(vector<vector<int>>& edges, int sz)
{
    vector<set<int>> m(sz);
    vector<vector<int>> res(sz);
    for(auto e : edges)
    {
        m[e[0]].insert(e[1]);
        m[e[1]].insert(e[0]);
    }
    queue<int> q;
    q.push(0);
    while(!q.empty())
    {
        int el = q.front();
        q.pop();
        for(auto e : m[el])
        {
            m[e].erase(el);
            q.push(e);
        }
    }
    for(int i=0;i<sz;i++)
        for(auto e : m[i]) res[i].push_back(e);
    return res;
}

vector<int> buildDirectGraphToRoot(vector<vector<int>>& graphRootToLeaf, int sz)
{
    vector<int> res(sz);
    for(int i=0;i<sz;i++)
        for(int j=0;j<graphRootToLeaf[i].size();j++) res[graphRootToLeaf[i][j]]=i;
    return res;
}