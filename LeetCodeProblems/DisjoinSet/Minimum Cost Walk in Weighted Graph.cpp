#include <vector>
using namespace std;

class DisjoinSetUnion {
public:
    DisjoinSetUnion(int sz): parent(sz), rank(sz), sz(sz)
    {
        for(int i = 0; i < sz; i++)
        {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int find_set(int v) {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }

    void connect(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (rank[a] < rank[b])
                swap(a, b);
            parent[b] = a;
            if (rank[a] == rank[b])
                rank[a]++;
        }
    }

    bool are_connect(int x, int y)
    {
        return (find_set(x) == find_set(y));
    }

    int get_sets()
    {
        int sets = 0;
        for(int i = 0; i < sz; i++)
            if(parent[i] == i) sets++;
        return sets;
    }
    void combine(vector<vector<int>>& edges)
    {
        for(int i=0;i<sz;i++) find_set(i);
        map<int,vector<int>> m;
        for(int i=0;i<sz;i++) m[parent[i]].push_back(i);
        map<int,int> res;
        val.resize(sz);
        for(auto e : edges)
        {
            int p = parent[e[0]];
            if(res.count(p)==0) res[p]=e[2];
            else res[p]&=e[2];
        }
        for(auto [k,v] : m)
        {
            for(auto e : v) val[e]=res[parent[e]];
        }
    }
    int getCost(int a)
    {
        return val[a];
    }

    vector<int> parent;
    vector<int> rank;
    vector<int> val;
    int sz;
};

class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        DisjoinSetUnion ds(n);
        for(auto e : edges)
        {
            ds.connect(e[0],e[1]);
        }
        ds.combine(edges);
        vector<int> r;
        for(auto e : query)
        {
            if(e[0]==e[1]) r.push_back(0);
            else if(ds.are_connect(e[0],e[1])) r.push_back(ds.getCost(e[0]));
            else r.push_back(-1);
        }
        return r;
    }
};